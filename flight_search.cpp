#include "flight_search.h"
#include "ui_flight_search.h"
#include "buy.h"
#include "special_search.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <qstackedwidget.h>
#include <QStackedLayout>
#include <QTimer>


Flight_sereach::Flight_sereach(QString userAccount,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Flight_sereach),
    userAccount(userAccount)
{
    ui->setupUi(this);
    QPixmap pixmap(":/img/bgground2.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(palette);
    setAutoFillBackground(true);
    setFixedSize(1061, 611);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->lineEditChu->setPlaceholderText("出发地");
    ui->lineEditDao->setPlaceholderText("到达地");

    //当前时间
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);


    // 筛选按钮槽函数
    connect(ui->timeearly, &QPushButton::clicked, this, &Flight_sereach::sortTimeEarly);
    connect(ui->timelate, &QPushButton::clicked, this, &Flight_sereach::sortTimeLate);
    connect(ui->pricelow, &QPushButton::clicked, this, &Flight_sereach::sortPriceLow);
    connect(ui->pricehigh, &QPushButton::clicked, this, &Flight_sereach::sortPriceHigh);

    connect(ui->pushButton_3,&QPushButton::clicked,this,[=]{
        userPanel.receiveUserInfo(userAccount);
        userPanel.show();
        this->close();
    });

    // 用户中心关闭的信号连接
    // connect(&userPanel,&UserPanel::user_panel_closed,this,[=]{
    //     this->show();
    // });

    userPanel.receiveUserInfo(userAccount);
    checkTodaysFlights();
}



Flight_sereach::~Flight_sereach()
{
    delete ui;
}

void Flight_sereach:: checkTodaysFlights() {
    // 获取当前日期
    QDate currentDate = QDate::currentDate();

    // 准备SQL查询语句，查找与当前用户账号相关的所有订单
    QSqlQuery query;
    QString sql = "SELECT user_ID FROM `user` WHERE user_account = :account";
    query.prepare(sql);
    query.bindValue(":account", userAccount);
    if (!query.exec()) {
        // 处理查询错误
        qDebug() << "查询失败:" << query.lastError();
        return;
    }
    while(query.next()){
        ID = query.value("user_ID").toString();
        qDebug()<<ID;
    }


    sql = "SELECT flightNo, date,departCityName,arriveCityName FROM `order` WHERE user_account = :account OR passID = :ID";
    query.prepare(sql);
    query.bindValue(":account", userAccount);
    query.bindValue(":ID", ID);

    if (!query.exec()) {
        // 处理查询错误
        qDebug() << "查询失败:" << query.lastError();
        return;
    }

    QString flightNumbers;
    QString departCityName;
    QString arriveCityName;
    while (query.next()) {
        // 从查询结果中获取日期和航班号
        QDate orderDate = query.value("date").toDate();
        QString flightNumber = query.value("flightNo").toString();
        qDebug()<<flightNumber;
        // 检查订单日期是否与今天相同
        if (orderDate == currentDate) {
            flightNumbers=flightNumber;
            departCityName=query.value("departCityName").toString();
            arriveCityName=query.value("arriveCityName").toString();
        }
    }
    // query.clear();
    // 如果有今天的航班，弹出提醒窗口
    if (!flightNumbers.isEmpty()) {
        QString message = "您今天有航班" + flightNumbers + "从" + departCityName + "飞往" + arriveCityName + "，请做好出行准备。";
        QMessageBox::information(nullptr, "今日航班提醒", message);
    }

    sql = "SELECT flightNo,departCityName,arriveCityName FROM `order` WHERE (user_account = :account OR passID = :ID) AND status=5";
    query.prepare(sql);
    query.bindValue(":account", userAccount);
    query.bindValue(":ID", ID);
    qDebug()<<ID;

    if (!query.exec()) {
        // 处理查询错误
        qDebug() << "查询失败:" << query.lastError();
        return;
    }
    // query.first();

    QString flightNumber;
    while (query.next()) {
        // 从查询结果中获取日期和航班号
        flightNumber = query.value("flightNo").toString();

        departCityName=query.value("departCityName").toString();
        arriveCityName=query.value("arriveCityName").toString();
    }


    // 如果有今天的航班，弹出提醒窗口
    if (!flightNumber.isEmpty()) {
        QString message = "您的航班" + flightNumber + "从" + departCityName + "飞往" + arriveCityName + "发生了航变，请留意。";
        QMessageBox::information(nullptr, "今日航班提醒", message);
    }

    sql = "SELECT flightNo,departCityName,arriveCityName FROM `order` WHERE (user_account = :account OR passID = :ID) AND status=6";
    query.prepare(sql);
    query.bindValue(":account", userAccount);
    query.bindValue(":ID", ID);
    qDebug()<<ID;

    if (!query.exec()) {
        // 处理查询错误
        qDebug() << "查询失败:" << query.lastError();
        return;
    }
    // query.first();

    QString flightNumber2;
    while (query.next()) {
        // 从查询结果中获取日期和航班号
        flightNumber2 = query.value("flightNo").toString();

        departCityName=query.value("departCityName").toString();
        arriveCityName=query.value("arriveCityName").toString();
    }


    // 如果有今天的航班，弹出提醒窗口
    if (!flightNumber2.isEmpty()) {
        QString message = "您的航班" + flightNumber2 + "从" + departCityName + "飞往" + arriveCityName + "被取消，请留意。";
        QMessageBox::information(nullptr, "今日航班提醒", message);
    }
}

void Flight_sereach::timerUpdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->labDateTime->setText(str);
}

//打开数据库
bool Flight_sereach::openDatabase() {
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
void Flight_sereach::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

//搜索按钮槽函数
void Flight_sereach::on_pushButton_clicked()
{
    // checkTodaysFlights();
    //清空tablewidget
    ui->tableWidget->clearContents();

    // 检查输入是否为空
    QString departCity = ui->lineEditChu->text().trimmed();
    QString arriveCity = ui->lineEditDao->text().trimmed();
    QDate date = ui->dateEdit->date();

    if (departCity.isEmpty() || arriveCity.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "出发地和目的地不能为空！");
        return;
    }




    QDate currentDate = QDate::currentDate();
    if (date < currentDate) {
        QMessageBox::warning(this, "输入错误", "时间已过！");
        return;
    }

    // 加载航班信息
    loadFlights(departCity, arriveCity, date);

}

//获取数据
void Flight_sereach::loadFlights(const QString &departCity, const QString &arriveCity, const QDate &date) {
    // 打开数据库连接
    if (!openDatabase()) {
        return;
    }

    // 第一步：从 flight 表中查询符合条件的航班
    QSqlQuery query;
    query.prepare("SELECT flightNo, airlineCompanyName, aircraftType, departTime, departPortName, "
                  "arriveTime, arrivePortName, onTimeRate, price FROM flight "
                  "WHERE departCityName = :departCity AND arriveCityName = :arriveCity");
    query.bindValue(":departCity", departCity);
    query.bindValue(":arriveCity", arriveCity);

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

void Flight_sereach::clearAndReloadTable(const QList<QMap<QString, QVariant>> &sortedList) {
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
        QPushButton *button = new QPushButton("订票", this);
        QObject::connect(button, &QPushButton::clicked, [this, row]() {
            onRowButtonClicked(row);  // 处理按钮点击事件
        });

        // 将按钮添加到单元格
        QWidget *widget = new QWidget(this);
        QHBoxLayout *layout = new QHBoxLayout(widget);
        layout->addWidget(button);
        layout->setContentsMargins(0, 0, 0, 0);
        ui->tableWidget->setCellWidget(row, 9, widget);

        ++row;
        qDebug() << "添加航班：" << flight["flightNo"].toString();
    }

    // 调整列宽以填满整个表格
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
}

//筛选功能
void Flight_sereach::sortFlightList(const QString &key, Qt::SortOrder order) {
    std::sort(flightList.begin(), flightList.end(), [key, order](const QMap<QString, QVariant> &a, const QMap<QString, QVariant> &b) {
        if (key == "departTime") {
            return order == Qt::AscendingOrder ? a[key].toTime() < b[key].toTime() : a[key].toTime() > b[key].toTime();
        } else if (key == "price") {
            return order == Qt::AscendingOrder ? a[key].toDouble() < b[key].toDouble() : a[key].toDouble() > b[key].toDouble();
        }
        return false;  // 默认情况下不排序
    });
}

void Flight_sereach::sortTimeEarly() {
    sortFlightList("departTime", Qt::AscendingOrder);
    clearAndReloadTable(flightList);
}

void Flight_sereach::sortTimeLate() {
    sortFlightList("departTime", Qt::DescendingOrder);
    clearAndReloadTable(flightList);
}

void Flight_sereach::sortPriceLow() {
    sortFlightList("price", Qt::AscendingOrder);
    clearAndReloadTable(flightList);
}

void Flight_sereach::sortPriceHigh() {
    sortFlightList("price", Qt::DescendingOrder);
    clearAndReloadTable(flightList);
}

void Flight_sereach::onRowButtonClicked(int row) {
    // 获取当前行的航班信息
    QMap<QString, QVariant> flight = getFlightInfo(row);

    // 获取查询条件
    QString departCity = getDepartCity();
    QString arriveCity = getArriveCity();
    QDate date = getDate();

    // 打开子页面并传递航班信息和其他信息
    Customor_DingPao *ding = new Customor_DingPao(flight, departCity, arriveCity, date, userAccount);
    // 订票界面关闭的信号连接
    connect(ding,&Customor_DingPao::customor_dingpao_closed,this,[=]{
        this->show();
    });

    this->close();
    ding->show();
}

QMap<QString, QVariant> Flight_sereach::getFlightInfo(int row) {
    // 确保行索引有效
    if (row < 0 || row >= flightList.size()) {
        return QMap<QString, QVariant>();
    }

    // 返回对应行的航班信息
    return flightList[row];
}

QString Flight_sereach::getDepartCity() const {
    return ui->lineEditChu->text();  // 假设出发城市是从组合框中获取的
}

QString Flight_sereach::getArriveCity() const {
    return ui->lineEditDao->text();  // 假设到达城市是从组合框中获取的
}

QDate Flight_sereach::getDate() const {
    return ui->dateEdit->date();  // 假设日期是从日期编辑器中获取的
}

void Flight_sereach::on_specialButton_clicked()
{
    Special_search *spe = new Special_search(userAccount);
    // connect(spe,&Special_search::special_search_closed,this,[=]{
    //     this->show();
    // });
    this->close();
    spe->show();
}

