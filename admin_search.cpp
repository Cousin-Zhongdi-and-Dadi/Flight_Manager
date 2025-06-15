#include "admin_search.h"
#include "ui_admin_search.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <qstackedwidget.h>


Admin_search::Admin_search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_search)
{
    ui->setupUi(this);

    //背景图片
    QPixmap pixmap(":/img/bgground2.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(palette);
    setAutoFillBackground(true);

    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);

    ui->lineEditChu->setPlaceholderText("出发地");
    ui->lineEditDao->setPlaceholderText("到达地");

    // 筛选按钮槽函数
    connect(ui->timeearly, &QPushButton::clicked, this, &Admin_search::sortTimeEarly);
    connect(ui->timelate, &QPushButton::clicked, this, &Admin_search::sortTimeLate);
    connect(ui->pricelow, &QPushButton::clicked, this, &Admin_search::sortPriceLow);
    connect(ui->pricehigh, &QPushButton::clicked, this, &Admin_search::sortPriceHigh);

}

Admin_search::~Admin_search()
{
    delete ui;
}

//打开数据库
bool Admin_search::openDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost"); // MySQL服务器地址
    db.setDatabaseName("flight_db"); // 数据库名
    db.setUserName("root"); // 用户名
    db.setPassword("123456"); // 密码

    if (!db.open()) {
        QMessageBox::critical(this, "无法打开数据库", db.lastError().text());
        return false;
    }
    return true;
}


//关闭数据库
void Admin_search::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

//搜索按钮槽函数
void Admin_search::on_pushButton_clicked()
{
    //清空tablewidget
    ui->tableWidget->clearContents();

    // 检查输入是否为空
    QString departCity = ui->lineEditChu->text().trimmed();
    QString arriveCity = ui->lineEditDao->text().trimmed();
    QDate date = ui->dateEdit->date();

    // if (departCity.isEmpty() || arriveCity.isEmpty()) {
    //     QMessageBox::warning(this, "输入错误", "出发地和目的地不能为空！");
    //     return;
    // }

    // 加载航班信息
    loadFlights(departCity, arriveCity, date);

}

//获取数据
void Admin_search::loadFlights(const QString &departCity, const QString &arriveCity, const QDate &date) {
    // 打开数据库连接
    if (!openDatabase()) {
        return;
    }

    QSqlQuery query;

    if(departCity.isEmpty() && arriveCity.isEmpty()){
        query.prepare("SELECT flightNo, airlineCompanyName, aircraftType, departTime, departPortName, "
                      "arriveTime, arrivePortName, onTimeRate, price FROM flight ");
    }

    // 第一步：从 flight 表中查询符合条件的航班
    else{
    query.prepare("SELECT flightNo, airlineCompanyName, aircraftType, departTime, departPortName, "
                  "arriveTime, arrivePortName, onTimeRate, price FROM flight "
                  "WHERE departCityName = :departCity AND arriveCityName = :arriveCity");
    query.bindValue(":departCity", departCity);
    query.bindValue(":arriveCity", arriveCity);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "查询失败", query.lastError().text());
        closeDatabase();
        return;
    }

    // 将查询结果存储在一个临时列表中
    flightList.clear();
    while (query.next()) {
        QMap<QString, QVariant> flight;
        flight["flightNo"] = query.value(0).toString();
        flight["airlineCompanyName"] = query.value(1).toString();
        flight["aircraftType"] = query.value(2).toString();
        flight["departTime"] = query.value(3).toTime();
        flight["departPortName"] = query.value(4).toString();
        flight["arriveTime"] = query.value(5).toTime();
        flight["arrivePortName"] = query.value(6).toString();
        flight["onTimeRate"] = query.value(7).toDouble();
        flight["price"] = query.value(8).toDouble();
        flightList.append(flight);
        qDebug() << "找到航班：" << flight["flightNo"].toString();
        qDebug() << date;
    }

    if (flightList.isEmpty()) {
        qWarning() << "没有找到符合条件的航班。";
        QMessageBox::information(this, "查询结果", "没有找到符合条件的航班。");
        closeDatabase();
        return;
    }

    // 第二步：根据 date 检索 schedule 表，并过滤掉不在 schedule 表中的航班
    QString scheduleTableName = "schedule" + date.toString("yyyyMMdd");
    qDebug() << "开始检索调度表：" << scheduleTableName;

    for (auto it = flightList.begin(); it != flightList.end(); ) {
        QSqlQuery scheduleQuery;
        scheduleQuery.prepare(QString("SELECT COUNT(*) FROM %1 WHERE flightNo = :flightNo").arg(scheduleTableName));
        scheduleQuery.bindValue(":flightNo", (*it)["flightNo"].toString());

        if (!scheduleQuery.exec()) {
            qCritical() << "查询调度表失败：" << scheduleQuery.lastError().text();
            closeDatabase();
            return;
        }

        if (scheduleQuery.next() && scheduleQuery.value(0).toInt() == 0) {
            qDebug() << "航班" << (*it)["flightNo"].toString() << "不在调度表" << scheduleTableName << "中，移除该航班。";
            it = flightList.erase(it); // 移除不在 schedule 表中的航班
        } else {
            ++it;
        }
    }

    if (flightList.isEmpty()) {
        qWarning() << "所有航班都不在调度表" << scheduleTableName << "中，没有符合条件的航班。";
        QMessageBox::information(this, "查询结果", "该日无直飞航班。");
        closeDatabase();
        return;
    }

    clearAndReloadTable(flightList);

    qDebug() << "航班信息显示完成。";

    closeDatabase();
}

void Admin_search::clearAndReloadTable(const QList<QMap<QString, QVariant>> &sortedList) {
    // 清空现有的表格内容
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(sortedList.size());

    int row = 0;
    for (const auto &flight : qAsConst(sortedList)) {
        // 航班号
        QTableWidgetItem *itemFlightNo = new QTableWidgetItem(flight["flightNo"].toString());
        ui->tableWidget->setItem(row, 0, itemFlightNo);

        // 航空公司
        QTableWidgetItem *itemAirline = new QTableWidgetItem(flight["airlineCompanyName"].toString());
        ui->tableWidget->setItem(row, 1, itemAirline);

        // 机型
        QTableWidgetItem *itemAircraft = new QTableWidgetItem(flight["aircraftType"].toString());
        ui->tableWidget->setItem(row, 2, itemAircraft);

        // 起飞时间
        QTableWidgetItem *itemDepartTime = new QTableWidgetItem(flight["departTime"].toTime().toString("hh:mm"));
        ui->tableWidget->setItem(row, 3, itemDepartTime);

        // 出发机场
        QTableWidgetItem *itemDepartPort = new QTableWidgetItem(flight["departPortName"].toString());
        ui->tableWidget->setItem(row, 4, itemDepartPort);

        // 到达时间
        QTableWidgetItem *itemArriveTime = new QTableWidgetItem(flight["arriveTime"].toTime().toString("hh:mm"));
        ui->tableWidget->setItem(row, 5, itemArriveTime);

        // 到达机场
        QTableWidgetItem *itemArrivePort = new QTableWidgetItem(flight["arrivePortName"].toString());
        ui->tableWidget->setItem(row, 6, itemArrivePort);

        // 准点率
        QTableWidgetItem *itemOnTimeRate = new QTableWidgetItem(QString::number(flight["onTimeRate"].toDouble(), 'f', 2) + "%");
        ui->tableWidget->setItem(row, 7, itemOnTimeRate);

        // 票价
        QTableWidgetItem *itemPrice = new QTableWidgetItem(QString::number(flight["price"].toDouble(), 'f', 2));
        ui->tableWidget->setItem(row, 8, itemPrice);

        // 操作按钮
        QPushButton *button = new QPushButton("编辑", this);
        QObject::connect(button, &QPushButton::clicked, [this, row]() {
            onRowButtonClicked(row);  // 处理按钮点击事件
        });

        // 将按钮添加到单元格
        QWidget *widget = new QWidget(this);
        QHBoxLayout *layout = new QHBoxLayout(widget);
        layout->addWidget(button);
        layout->setContentsMargins(0, 0, 0, 0);
        ui->tableWidget->setCellWidget(row, 9, widget);

        // 操作按钮
        QPushButton *button2 = new QPushButton("删除", this);
        QObject::connect(button2, &QPushButton::clicked, [this, row]() {
            onRowButton2Clicked(row);  // 处理按钮点击事件
        });

        // 将按钮添加到单元格
        QWidget *widget2 = new QWidget(this);
        QHBoxLayout *layout2 = new QHBoxLayout(widget2);
        layout2->addWidget(button2);
        layout2->setContentsMargins(0, 0, 0, 0);
        ui->tableWidget->setCellWidget(row, 10, widget2);

        ++row;
        qDebug() << "添加航班：" << flight["flightNo"].toString();
    }



    // 调整列宽以填满整个表格
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
}
//修改
void Admin_search::onRowButtonClicked(int row) {

    QDate date = getDate();
    QDate currentDate = QDate::currentDate();

    if (date < currentDate) {
        QMessageBox::warning(this, "输入错误", "时间已过！");
        return;
    }

    // 获取当前行的航班信息
    QString flightNo = ui->tableWidget->item(row, 0)->text();
    QString departTimeString = ui->tableWidget->item(row, 3)->text(); // 假设此列包含时间字符串，格式为 hh:mm:ss
    QString arriveTimeString = ui->tableWidget->item(row, 5)->text(); // 假设此列也包含时间字符串，格式为 hh:mm:ss


    QTime departTime = QTime::fromString(departTimeString, "hh:mm");
    QString formattedDepartTime = departTime.toString("hh:mm:ss");

    QTime arriveTime = QTime::fromString(arriveTimeString, "hh:mm");
    QString formattedArriveTime = arriveTime.toString("hh:mm:ss");
    qDebug() << "Departure Time:" << flightNo;
    qDebug() << "Arrival Time:" << formattedArriveTime;
    // 准备SQL更新语句
    QSqlQuery query;

    query.prepare("UPDATE flight_db.order SET "
                  "departTime = :departTime, "
                  "arriveTime = :arriveTime, "
                  "status = 5 "
                  "WHERE flightNo = :flightNo AND date = :date AND status = 1");

    // 绑定参数值
    query.bindValue(":flightNo", flightNo);
    query.bindValue(":date", date.toString("yyyy-MM-dd")); // 确保日期格式为 yyyy-MM-dd
    query.bindValue(":departTime", formattedDepartTime); // 确保时间格式为 hh:mm:ss
    query.bindValue(":arriveTime", formattedArriveTime); // 确保时间格式为 hh:mm:ss


    // 执行更新操作
    if (!query.exec()) {
        qDebug() << "Update failed"<<query.lastError().text();
        return;
    } else {
        // 显示成功提示并关闭窗口
        QMessageBox::information(this, "成功", "修改成功");
    }



}
//删除
void Admin_search::onRowButton2Clicked(int row) {

    QDate date = getDate();
    QDate currentDate = QDate::currentDate();

    if (date < currentDate) {
        QMessageBox::warning(this, "输入错误", "时间已过！");
        return;
    }
    QString flightNo = ui->tableWidget->item(row, 0)->text();
    QSqlQuery query;
    query.prepare("UPDATE flight_db.order SET "
                  "status = 6 "
                  "WHERE flightNo = :flightNo AND date = :date AND (status = 1 OR status = 5)");
    query.bindValue(":flightNo", flightNo);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));
    if (!query.exec()) {
        qDebug() << "Delete failed"<<query.lastError().text();
        return;
    } else {
        QMessageBox::information(this, "成功", "删除成功");
    }

    QString scheduleTableName = "schedule" + date.toString("yyyyMMdd");
    query.prepare(QString("DELETE FROM %1 WHERE flightNo = :flightNo").arg(scheduleTableName));
    query.bindValue(":flightNo", flightNo);
    if (!query.exec()) {
        qDebug() << "Delete failed"<<query.lastError().text();
        return;
    }

}

//筛选功能
void Admin_search::sortFlightList(const QString &key, Qt::SortOrder order) {
    std::sort(flightList.begin(), flightList.end(), [key, order](const QMap<QString, QVariant> &a, const QMap<QString, QVariant> &b) {
        if (key == "departTime") {
            return order == Qt::AscendingOrder ? a[key].toTime() < b[key].toTime() : a[key].toTime() > b[key].toTime();
        } else if (key == "price") {
            return order == Qt::AscendingOrder ? a[key].toDouble() < b[key].toDouble() : a[key].toDouble() > b[key].toDouble();
        }
        return false;  // 默认情况下不排序
    });
}

//按时间从早到晚
void Admin_search::sortTimeEarly() {
    sortFlightList("departTime", Qt::AscendingOrder);
    clearAndReloadTable(flightList);
}

//按时间从晚到早
void Admin_search::sortTimeLate() {
    sortFlightList("departTime", Qt::DescendingOrder);
    clearAndReloadTable(flightList);
}

//按票价从低到高
void Admin_search::sortPriceLow() {
    sortFlightList("price", Qt::AscendingOrder);
    clearAndReloadTable(flightList);
}

//按票价从高到低
void Admin_search::sortPriceHigh() {
    sortFlightList("price", Qt::DescendingOrder);
    clearAndReloadTable(flightList);
}



QString Admin_search::getDepartCity() const {
    return ui->lineEditChu->text();
}

QString Admin_search::getArriveCity() const {
    return ui->lineEditDao->text();
}

QDate Admin_search::getDate() const {
    return ui->dateEdit->date();
}

//返回管理员主界面
void Admin_search::on_pushButton_back_clicked()
{
    QWidget *parent = parentWidget();
    if (parent) {
        parent->show();
    }
    close();
}



