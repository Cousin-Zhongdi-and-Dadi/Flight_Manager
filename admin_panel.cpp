#include "admin_panel.h"
#include "admin_search.h"
#include <QDate>

FlightManager::FlightManager(QWidget *parent) : QMainWindow(parent), ui(new Ui::Form), searchUi(new Ui::SearchForm) {
    ui->setupUi(this);

    // 初始化查询订单
    searchWindow = new QWidget(); // 假设 searchWindow 是查询订单界面的容器
    searchUi->setupUi(searchWindow);

    // 连接信号和槽
    connect(ui->pushButton_2, &QPushButton::clicked, this, &FlightManager::addFlight);
    connect(ui->pushButton, &QPushButton::clicked, this, &FlightManager::showSearchWindow);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &FlightManager::jumpSearch);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &FlightManager::onExitButtonClicked);

    connect(searchUi->pushButton_3, &QPushButton::clicked, this, &FlightManager::hideSearchWindow);
    connect(searchUi->pushButton_4, &QPushButton::clicked, this, &FlightManager::jumpSearch2);
    connect(searchUi->pushButton_5, &QPushButton::clicked, this, &FlightManager::searchOrders);
    connect(searchUi->pushButton_6, &QPushButton::clicked, this, &FlightManager::onExitButtonClicked);

    // 初始化数据库连接
    initDatabase();
    setWindowTitle("Flight Manager");
}

void FlightManager::initDatabase() {
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("flight_db");
    db.setUserName("root");
    db.setPassword("123456");

    if (!db.open()) {
        qDebug() << "Error: Database connection failed!";
        qDebug() << "Database connection error:" << db.lastError().text();
    }
}

void FlightManager::addFlight() {
    if (!db.isOpen()) {
        qDebug() << "Database is not open.";
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
        return;
    }

    QString flightNo = ui->lineEdit->text();
    qDebug()<<flightNo;
    QString departDate = ui->dateEdit->date().toString("yyyy-MM-dd");
    qDebug()<<departDate;

    //检查是否有字段为空
    if (isAnyFieldEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("录入信息不完整"));
        return;
    }

    if(ui->dateEdit->date()<QDate::fromString("2024-12-28","yyyy-MM-dd")||ui->dateEdit->date()>QDate::fromString("2025-01-05","yyyy-MM-dd")){
        QMessageBox::warning(this, "输入错误", "日期错误");
        return;
    }

    // 检查航班号是否冲突
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM flight WHERE flightNo = :flightNo");
    query.bindValue(":flightNo", flightNo);
    if (!query.exec()) {
        qDebug() << "Error: Failed to execute query.";
        qDebug() << "Query error:" << query.lastError().text();
        QMessageBox::critical(this, "Query Error", "Failed to check flight number: " + query.lastError().text());
        return;
    }

    if (query.next() && query.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Flight Number Conflict", "Flight number is already in use.");
        return;
    }

    // 插入航班信息到flight表
    query.prepare("INSERT INTO flight (flightNo, aircraftType, departTime, arriveTime, departPortName, departTerminal, arrivePortName, arriveTerminal, departDate, price, airlineCompanyName, stopCityName, departCityName, arriveCityName) "
                  "VALUES (:flightNo, :aircraftType, :departTime, :arriveTime, :departPortName, :departTerminal, :arrivePortName, :arriveTerminal, :departDate, :price, :airlineCompanyName, :stopCityName, :departCityName, :arriveCityName)");
    query.bindValue(":flightNo", ui->lineEdit->text());
    qDebug()<<ui->lineEdit->text();
    query.bindValue(":aircraftType", ui->lineEdit_2->text());
    qDebug()<<ui->lineEdit->text();
    query.bindValue(":departTime", ui->timeEdit->time());
    qDebug()<<ui->timeEdit->time();
    query.bindValue(":arriveTime", ui->timeEdit_2->time());
    qDebug()<<ui->lineEdit_2->text();
    query.bindValue(":departPortName", ui->lineEdit_3->text());
    qDebug()<<ui->lineEdit_3->text();
    query.bindValue(":departTerminal", ui->lineEdit_4->text());
    qDebug()<<ui->lineEdit_4->text();
    query.bindValue(":arrivePortName", ui->lineEdit_5->text());
    qDebug()<<ui->lineEdit_5->text();
    query.bindValue(":arriveTerminal", ui->lineEdit_6->text());
    qDebug()<<ui->lineEdit_6->text();
    query.bindValue(":departDate", departDate);
    qDebug()<<departDate;
    query.bindValue(":price", ui->lineEdit_7->text().toDouble());
    qDebug()<<ui->lineEdit_7->text();
    query.bindValue(":airlineCompanyName", ui->lineEdit_8->text());
    qDebug()<<ui->lineEdit_8->text();
    query.bindValue(":stopCityName", ui->lineEdit_9->text());
    qDebug()<<ui->lineEdit_9->text();
    query.bindValue(":departCityName", ui->lineEdit_10->text());
    qDebug()<<ui->lineEdit_10->text();
    query.bindValue(":arriveCityName", ui->lineEdit_11->text());
    qDebug()<<ui->lineEdit_11->text();

    if (!query.exec()) {
        qDebug() << "Error: Failed to insert into flight table.";
        qDebug() << "Query error:" << query.lastError().text();
        QMessageBox::critical(this, "Insert Error", "Failed to insert flight information: " + query.lastError().text());
        return;
    }

    // 插入航班信息到对应的schedule表
    QString scheduleTable = "schedule" + departDate.replace("-", ""); // 根据出发日期生成对应的schedule表名
    query.prepare("INSERT INTO " + scheduleTable + " (flightNo, date, eco_seat, bus_seat, pri_seat, price) VALUES (:flightNo, :date, :eco_seat, :bus_seat, :pri_seat, :price)");
    query.bindValue(":flightNo", ui->lineEdit->text());
    qDebug()<<ui->lineEdit->text();
    query.bindValue(":date", departDate);
    query.bindValue(":eco_seat", ui->lineEdit_12->text().toInt());
    qDebug()<<ui->lineEdit_12->text().toInt();
    query.bindValue(":bus_seat", ui->lineEdit_13->text().toInt());
    qDebug()<<ui->lineEdit_13->text().toInt();
    query.bindValue(":pri_seat", ui->lineEdit_14->text().toInt());
    qDebug()<<ui->lineEdit_14->text().toInt();
    query.bindValue(":price", ui->lineEdit_7->text().toDouble());
    qDebug()<<ui->lineEdit_7->text().toDouble();

    if (!query.exec()) {
        qDebug() << "Error: Failed to insert into schedule table.";
        qDebug() << "Query error:" << query.lastError().text();
        QMessageBox::critical(this, "Insert Error", "Failed to insert schedule information: " + query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Flight information added successfully.");
}

void FlightManager::searchOrders() {
    if (!db.isOpen()) {
        qDebug() << "Database is not open.";
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
        return;
    }

    QString flightNo = searchUi->lineEdit->text();
    QString userID = searchUi->lineEdit_2->text(); // 用户ID输入框
    QDate date = searchUi->dateEdit->date(); // 获取日期值

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query(db);
    QString queryStr = "SELECT * FROM `order` WHERE 1=1";

    // 检查航班号是否为空，如果不为空，则添加到查询条件
    if (!flightNo.isEmpty()) {
        queryStr += " AND flightNo = :flightNo";
    }

    // 检查用户ID是否为空，如果不为空，则添加到查询条件
    if (!userID.isEmpty()) {
        queryStr += " AND user_account = :userID";
    }

    // 检查日期是否为默认值“2000-01-01”，如果不是，则添加到查询条件
    if (date != QDate(2000, 1, 1) && date.isValid()) {
        queryStr += " AND date = :date";
    }

    qDebug() << queryStr;
    query.prepare(queryStr);
    if (!flightNo.isEmpty()) {
        query.bindValue(":flightNo", flightNo);
    }
    if (!userID.isEmpty()) {
        query.bindValue(":userID", userID);
    }
    if (date != QDate(2000, 1, 1) && date.isValid()) {
        query.bindValue(":date", date.toString("yyyy-MM-dd"));
    }

    if (!query.exec()) {
        qDebug() << "Error: Failed to execute query.";
        qDebug() << "Query error:" << query.lastError().text();
        QMessageBox::critical(this, "Query Error", "Failed to search orders: " + query.lastError().text());
        return;
    }

    model->setQuery(query);
    searchUi->tableView->setModel(model);
    searchUi->tableView->resizeColumnsToContents();
    searchUi->tableView->show();
}

void FlightManager::showSearchWindow() {
    this->hide();
    searchWindow->show();
}

void FlightManager::hideSearchWindow() {
    searchWindow->hide();
    this->show();
}

void FlightManager::jumpSearch(){
    Admin_search *adsearch=new Admin_search(this);
    adsearch->show();
}

void FlightManager::jumpSearch2(){
    searchWindow->hide();
    this->show();
    Admin_search *adsearch=new Admin_search(this);
    adsearch->show();
}

//添加航班时检查是否所有字段已填写完
bool FlightManager::isAnyFieldEmpty() {
    // 检查所有 QLineEdit 的 text 是否为空
    if (ui->lineEdit->text().trimmed().isEmpty() ||
        ui->lineEdit_2->text().trimmed().isEmpty() ||
        ui->lineEdit_3->text().trimmed().isEmpty() ||
        ui->lineEdit_4->text().trimmed().isEmpty() ||
        ui->lineEdit_5->text().trimmed().isEmpty() ||
        ui->lineEdit_6->text().trimmed().isEmpty() ||
        ui->lineEdit_7->text().trimmed().isEmpty() || // 价格字段也应检查是否为空
        ui->lineEdit_8->text().trimmed().isEmpty() ||
        ui->lineEdit_10->text().trimmed().isEmpty() ||
        ui->lineEdit_11->text().trimmed().isEmpty()) {
        return true;
    }

    // 检查 QTimeEdit 和其他非字符串类型的数据
    // 如果你的 departDate 是 QDate 类型，你应该检查它是否为默认值或无效
    // 对于时间和日期，通常不需要检查是否为空，因为它们有默认值
    // 但是如果你希望确保用户已经选择了有效的时间或日期，你可以这样做：
    // if (!ui->timeEdit->time().isValid() ||
    //     !ui->timeEdit_2->time().isValid() ||
    //     !departDate.isValid()) { // 假设 departDate 是 QDate 类型
    //     return true;
    // }

    // 如果需要检查价格是否有效数字，可以在转换为 double 之前进行验证
    bool ok;
    ui->lineEdit_7->text().toDouble(&ok);
    if (!ok) {
        return true;
    }

    return false; // 所有字段都已正确填写
}
