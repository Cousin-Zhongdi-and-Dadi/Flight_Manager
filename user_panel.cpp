#include "user_panel.h"
#include "ui_user_panel.h"
#include "denglu.h"
#include "flight_search.h"

#include "opendatabase.h"

// 构造函数
UserPanel::UserPanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserPanel)
{
    ui->setupUi(this);

    // 初始化数据库连接
    dbcon = openDatabase::startDatabase();  // 调用startDatabase()方法来启动并返回数据库连接

    // 从数据库中读取用户信息
    if (!searchUserFromDatabase(user.user_account)) {
        qDebug() << "Failed to read data from user";
    }

    // 设置用户信息标签文本
    ui->nameLabel->setText("姓名：" + user.user_name);
    ui->accountLabel->setText("账号：" + user.user_account);
    ui->phoneLabel->setText("手机号：" + user.user_phone);
    ui->ID_Label->setText("身份证号：" + user.user_ID);

    // 设置标签文本颜色为黑色
    ui->nameLabel->setStyleSheet("color:black;");
    ui->accountLabel->setStyleSheet("color:black;");
    ui->phoneLabel->setStyleSheet("color:black;");
    ui->ID_Label->setStyleSheet("color:black;");

    // 设置窗口固定大小和标题
    setFixedSize(1061, 611);
    setWindowTitle("个人中心");

    // 设置窗口背景图片
    QPixmap pixmap(":/img/panel.png");
    pixmap = pixmap.scaled(1061, 611, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(palette);
    setAutoFillBackground(true);

    // 创建改签和编辑用户信息的对话框实例
    customer_gaiqian = new customer_GaiQian();
    user_info_edit = new userInfoEdit();

    // 当改签窗口关闭时刷新表格数据
    connect(customer_gaiqian, &customer_GaiQian::customer_gaiqian_closed, this, [=]{
        qDebug() << "refresh table";
        readDataFromDatabase();  // 刷新数据表
        this->show();  // 显示当前窗口
    });

    // 当点击修改个人信息按钮时显示编辑用户信息窗口
    connect(ui->changePersonInfoButton, &QPushButton::clicked, this, [=]{
        user_info_edit->receiveUserFromUserPanel(user);  // 将当前用户信息传递给编辑窗口
        user_info_edit->show();  // 显示编辑用户信息窗口
    });

    // 当编辑用户信息窗口关闭时刷新用户信息
    connect(user_info_edit, &userInfoEdit::user_info_edit_closed, this, [=]{
        qDebug() << "refresh table";
        searchUserFromDatabase(user.user_account);  // 重新查询用户信息
        ui->nameLabel->setText("姓名：" + user.user_name);
        ui->accountLabel->setText("账号：" + user.user_account);
        ui->phoneLabel->setText("手机号：" + user.user_phone);
        ui->ID_Label->setText("身份证号：" + user.user_ID);
    });

    // 当点击刷新按钮时刷新表格数据
    connect(ui->refreshButton, &QPushButton::clicked, this, [=]{
        readDataFromDatabase();  // 刷新数据表
        qDebug() << "refresh table";
        QMessageBox::information(this, "成功", "刷新成功");  // 显示刷新成功的消息框
    });

    // 当点击返回按钮时打开航班查询窗口并关闭当前窗口
    connect(ui->backwardButton, &QPushButton::clicked, this, [=]{
        Flight_sereach* fs = new Flight_sereach(user.user_account);  // 创建航班查询窗口实例
        fs->show();  // 显示航班查询窗口
        this->close();  // 关闭当前窗口
    });

    if(!openDatabase::checkDateAndRefreshDatabase()){
        qDebug()<<"failed to check flights on early date";
    }
}

// 析构函数
UserPanel::~UserPanel()
{
    delete ui;
}

// 从数据库读取用户订单信息并填充到表格中
bool UserPanel::readDataFromDatabase() {
    // 禁用表格排序，防止在数据加载过程中出现意外排序
    ui->userOrderTable->setSortingEnabled(false);

    // 清空表格内容
    ui->userOrderTable->clear();

    // 准备SQL查询语句，查找与当前用户账号相关的所有订单
    QSqlQuery query;
    QString sql = QString("SELECT * FROM `order` WHERE user_account = '%1' OR passID = '%2'").arg(user.user_account).arg(user.user_ID);
    query.prepare(sql);

    // 执行查询
    if (!query.exec()) {
        qDebug() << "Query failed";
        return false;
    }

    int rowCount = 0;

    // 设置表头
    QStringList headers;
    headers << "订单号" << "乘机人" << "乘机人身份证号" << "航班号" << "日期" << "出发时间" << "到达时间"
            << "出发城市名称" << "到达城市名称" << "票型" << "价格" << "状态" << "操作";

    int columnCount = headers.size();
    ui->userOrderTable->setRowCount(0);  // 设置行数为0，准备插入新数据
    ui->userOrderTable->setColumnCount(columnCount);  // 设置列数

    // 为每一列设置表头项
    for (int i = 0; i < headers.size(); ++i) {
        ui->userOrderTable->setHorizontalHeaderItem(i, new QTableWidgetItem(headers.at(i)));
    }

    // 遍历查询结果，逐行填充表格
    while (query.next()) {
        ui->userOrderTable->insertRow(rowCount);  // 插入新行

        // 填充各列数据
        ui->userOrderTable->setItem(rowCount, 0, new QTableWidgetItem());
        ui->userOrderTable->item(rowCount, 0)->setData(Qt::DisplayRole, query.value("order_ID").toInt());
        ui->userOrderTable->setItem(rowCount, 1, new QTableWidgetItem(query.value("passName").toString()));
        ui->userOrderTable->setItem(rowCount, 2, new QTableWidgetItem(query.value("passID").toString()));
        ui->userOrderTable->setItem(rowCount, 3, new QTableWidgetItem(query.value("flightNo").toString()));
        ui->userOrderTable->setItem(rowCount, 4, new QTableWidgetItem(query.value("date").toString()));
        QString departTime = query.value("departTime").toString().left(8);
        ui->userOrderTable->setItem(rowCount, 5, new QTableWidgetItem(departTime));
        QString arriveTime = query.value("arriveTime").toString().left(8);
        ui->userOrderTable->setItem(rowCount, 6, new QTableWidgetItem(arriveTime));
        ui->userOrderTable->setItem(rowCount, 7, new QTableWidgetItem(query.value("departCityName").toString()));
        ui->userOrderTable->setItem(rowCount, 8, new QTableWidgetItem(query.value("arriveCityName").toString()));
        double price = query.value("price").toDouble();
        ui->userOrderTable->setItem(rowCount, 10, new QTableWidgetItem());
        ui->userOrderTable->item(rowCount, 10)->setData(Qt::DisplayRole, price);

        // 票型列
        if (query.value("eco").toInt() == 1) {
            ui->userOrderTable->setItem(rowCount, 9, new QTableWidgetItem("经济舱"));
        } else if (query.value("bus").toInt() == 1) {
            ui->userOrderTable->setItem(rowCount, 9, new QTableWidgetItem("商务舱"));
        } else if (query.value("pri").toInt() == 1) {
            ui->userOrderTable->setItem(rowCount, 9, new QTableWidgetItem("头等舱"));
        }

        // 状态列
        int status = query.value("status").toInt();
        QString statusText;
        switch (status) {
        case 1: statusText = "正常"; break;
        case 2: statusText = "改签"; break;
        case 3: statusText = "退票"; break;
        case 4: statusText = "已使用"; break;
        case 5: statusText = "时刻变动"; break;
        case 6: statusText = "航班取消"; break;
        default: statusText = "未知"; break;
        }
        ui->userOrderTable->setItem(rowCount, 11, new QTableWidgetItem(statusText));

        // 操作按钮（改签、退票）
        QPushButton *changeButton = new QPushButton("改签");
        QPushButton *refundButton = new QPushButton("退票");
        if (statusText == "改签" || statusText == "退票" || statusText == "已使用") {
            changeButton->setDisabled(true);
            refundButton->setDisabled(true);
        }

        QHBoxLayout *buttonLayout = new QHBoxLayout();
        buttonLayout->addWidget(changeButton);
        buttonLayout->addWidget(refundButton);
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        buttonLayout->setSpacing(5);

        QWidget *widget = new QWidget();
        widget->setLayout(buttonLayout);

        ui->userOrderTable->setCellWidget(rowCount, 12, widget);

        // 连接改签按钮点击事件
        connect(changeButton, &QPushButton::clicked, [this, rowCount] {
            qDebug() << "selected: " << rowCount;

            if(ui->userOrderTable->item(rowCount, 11)->text()=="已使用"){
                QMessageBox::warning(this,"警告","无法改签本航班，请关注航班起飞日期");
                return;
            }

            Order order;
            order.order_ID = ui->userOrderTable->item(rowCount, 0)->text().toInt();
            order.user_account = user.user_account;
            order.passName = ui->userOrderTable->item(rowCount, 1)->text();
            order.passID = ui->userOrderTable->item(rowCount, 2)->text();
            order.flightNo = ui->userOrderTable->item(rowCount, 3)->text();
            order.date = ui->userOrderTable->item(rowCount, 4)->text();
            order.departTime = ui->userOrderTable->item(rowCount, 5)->text();
            order.arriveTime = ui->userOrderTable->item(rowCount, 6)->text();
            order.departCityName = ui->userOrderTable->item(rowCount, 7)->text();
            order.arriveCityName = ui->userOrderTable->item(rowCount, 8)->text();
            if (ui->userOrderTable->item(rowCount, 9)->text() == "经济舱") {
                order.eco = 1;
                order.bus = 0;
                order.pri = 0;
            } else if (ui->userOrderTable->item(rowCount, 9)->text() == "商务舱") {
                order.eco = 0;
                order.bus = 1;
                order.pri = 0;
            } else if (ui->userOrderTable->item(rowCount, 9)->text() == "头等舱") {
                order.eco = 0;
                order.bus = 0;
                order.pri = 1;
            }
            order.price = ui->userOrderTable->item(rowCount, 10)->text().toDouble();
            order.status = (ui->userOrderTable->item(rowCount, 11)->text() == "正常") ? 1 : (ui->userOrderTable->item(rowCount, 11)->text() == "改签") ? 2 : 3;
            this->openChangeOrderWidget(order);
            this->hide();
        });

        // 连接退票按钮点击事件
        connect(refundButton, &QPushButton::clicked, [=] {
            qDebug() << "selected: " << rowCount;

            if(ui->userOrderTable->item(rowCount, 11)->text()=="已使用"){
                QMessageBox::warning(this,"警告","无法退票本航班，请关注航班起飞日期");
                return;
            }

            QMessageBox message;
            message.setWindowTitle("退票确认");
            message.setIcon(QMessageBox::Question);
            message.setText("确认退票吗？");
            message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            if (message.exec() == QMessageBox::Ok) {
                qDebug() << "退票" << ui->userOrderTable->item(rowCount, 0)->text();
                int orderID = ui->userOrderTable->item(rowCount, 0)->text().toInt();

                // 更新数据库中的状态
                QSqlQuery updateQuery;
                updateQuery.prepare("UPDATE flight_db.order SET status = 3 WHERE order_ID = :orderID");
                updateQuery.bindValue(":orderID", orderID);

                if (!updateQuery.exec()) {
                    qDebug() << "Update failed";
                    QMessageBox::critical(this, "Database Error", "Failed to update the status in the database.");
                    return;
                }

                //以下更新

                // 更新数据库中的票数
                QStringList date=ui->userOrderTable->item(rowCount, 4)->text().split("-");
                QSqlQuery ticketQuery;
                if (ui->userOrderTable->item(rowCount, 9)->text() == "经济舱") {
                    QString sql="UPDATE flight_db.schedule"+date[0]+date[1]+date[2]+" SET eco_seat = eco_seat + 1 WHERE flightNo = :flightNo";
                    ticketQuery.prepare(sql);
                    ticketQuery.bindValue(":flightNo",ui->userOrderTable->item(rowCount, 3)->text());
                } else if (ui->userOrderTable->item(rowCount, 9)->text() == "商务舱") {
                    QString sql="UPDATE flight_db.schedule"+date[0]+date[1]+date[2]+" SET bus_seat = bus_seat + 1 WHERE flightNo = :flightNo";
                    ticketQuery.prepare(sql);
                    ticketQuery.bindValue(":flightNo",ui->userOrderTable->item(rowCount, 3)->text());
                } else if (ui->userOrderTable->item(rowCount, 9)->text() == "头等舱") {
                    QString sql="UPDATE flight_db.schedule"+date[0]+date[1]+date[2]+" SET pri_seat = pri_seat + 1 WHERE flightNo = :flightNo";
                    ticketQuery.prepare(sql);
                    ticketQuery.bindValue(":flightNo",ui->userOrderTable->item(rowCount, 3)->text());
                }

                if (!ticketQuery.exec()) {
                    qDebug() << "Ticket update failed";
                }

                //以上更新

                // 更新表格中的状态显示
                ui->userOrderTable->item(rowCount, 11)->setText("退票");

                // 计算退票金额（扣除10%手续费）
                double refund_money = ui->userOrderTable->item(rowCount, 10)->text().toDouble() * 0.9;
                QString message = "退票成功！扣除10%手续费后，退还您 " + QString::number(refund_money) + " 元";
                QMessageBox::information(this, "Success", message);

                changeButton->setDisabled(true);
                refundButton->setDisabled(true);
            }
        });

        ++rowCount;
    }

    // 启用表格排序
    ui->userOrderTable->setSortingEnabled(true);

    return true;
}

// 接收用户信息并更新界面
bool UserPanel::receiveUserInfo(QString user_account) {
    this->user.user_account = user_account;
    qDebug() << "user account:" << user_account << user.user_account;

    // 从数据库中搜索用户信息
    if (searchUserFromDatabase(user_account)) {
        // 更新界面上的用户信息标签
        ui->nameLabel->setText("姓名：" + user.user_name);
        ui->accountLabel->setText("账号：" + user.user_account);
        ui->phoneLabel->setText("手机号：" + user.user_phone);
        ui->ID_Label->setText("身份证号：" + user.user_ID);

        // 读取并显示用户的订单信息
        readDataFromDatabase();
        return true;
    } else {
        return false;
    }
}

// 打开改签订单窗口
void UserPanel::openChangeOrderWidget(const Order &order) {
    customer_gaiqian->receiveOrder(order, dbcon);
    customer_gaiqian->show();
}

// 从数据库中搜索用户信息
bool UserPanel::searchUserFromDatabase(QString user_account) {
    QSqlQuery query;
    QString sql = QString("SELECT * FROM flight_db.user WHERE user_account = '%1'").arg(user_account);
    query.prepare(sql);

    // 执行查询
    if (!query.exec()) {
        qDebug() << "Query failed";
        return false;
    }

    // 如果查询到用户信息，则更新用户对象
    if (query.next()) {
        user.user_pass = query.value("user_pass").toString();
        user.user_ID = query.value("user_ID").toString();
        user.user_phone = query.value("user_phone").toString();
        user.user_name = query.value("user_name").toString();
        return true;
    } else {
        return false;
    }
}

// 处理“返回”按钮点击事件，退出应用程序
void UserPanel::on_backwardButton_2_clicked() {
    QApplication::quit();
}

// 处理窗口关闭事件，发出信号通知其他组件
void UserPanel::closeEvent(QCloseEvent *event) {
    emit user_panel_closed();
    event->accept();
}

// 处理“登出”按钮点击事件，显示登录窗口并关闭当前窗口
void UserPanel::on_logoutButton_clicked() {
    denglu *deng = new denglu();
    deng->show();
    this->close();
}


