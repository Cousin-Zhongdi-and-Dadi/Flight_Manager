#include "special_search.h"
#include "ui_special_search.h"
#include "buy.h"
#include "flight_search.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <qstackedwidget.h>


Special_search::Special_search(const QString &userAccount,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Special_search),
    userAccount(userAccount)
{
    ui->setupUi(this);
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
    // ui->lineEditDao->setPlaceholderText("到达地");

    // 筛选按钮槽函数
    connect(ui->timeearly, &QPushButton::clicked, this, &Special_search::sortTimeEarly);
    connect(ui->timelate, &QPushButton::clicked, this, &Special_search::sortTimeLate);
    connect(ui->pricelow, &QPushButton::clicked, this, &Special_search::sortPriceLow);
    connect(ui->pricehigh, &QPushButton::clicked, this, &Special_search::sortPriceHigh);


}

Special_search::~Special_search()
{
    delete ui;
}

//打开数据库
bool Special_search::openDatabase() {
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
void Special_search::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

//搜索按钮槽函数
void Special_search::on_pushButton_clicked()
{
    //清空tablewidget
    ui->tableWidget->clearContents();

    // 检查输入是否为空
    QString departCity = ui->lineEditChu->text().trimmed();
    // QString arriveCity = ui->lineEditDao->text().trimmed();
    QDate date = ui->dateEdit->date();

    if (departCity.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "出发地和目的地不能为空！");
        return;
    }

    QDate currentDate = QDate::currentDate();
    if (date < currentDate) {
        QMessageBox::warning(this, "输入错误", "时间已过！");
        return;
    }

    // 加载航班信息
    loadFlights(departCity,date);

}

void Special_search::sortAndLimitFlights(QList<QMap<QString, QVariant>> &flightList) {
    // 使用lambda表达式作为比较器，按 'price' 字段从小到大排序
    std::sort(flightList.begin(), flightList.end(), [](const QMap<QString, QVariant> &flight1, const QMap<QString, QVariant> &flight2) {
        return flight1["price"].toDouble() < flight2["price"].toDouble();
    });

    // 如果有超过50条记录，只保留前50条
    if (flightList.size() > 50) {
        flightList.erase(flightList.begin() + 50, flightList.end());
    }

    // 打印筛选后的结果（可选）
    for (const auto &flight : flightList) {
        qDebug() << "筛选后的航班：" << flight["flightNo"].toString()
                 << "价格：" << flight["price"].toDouble();
    }
}


//获取数据
void Special_search::loadFlights(const QString &departCity, const QDate &date) {
    // 打开数据库连接
    if (!openDatabase()) {
        return;
    }

    // 第一步：从 flight 表中查询符合条件的航班
    QSqlQuery query;
    query.prepare("SELECT flightNo, airlineCompanyName, aircraftType, departTime, departPortName, "
                  "arriveTime, arrivePortName, onTimeRate, price, arriveCityName FROM flight "
                  "WHERE departCityName = :departCity");
    query.bindValue(":departCity", departCity);
    // query.bindValue(":arriveCity", arriveCity);

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
        flight["destination"] = query.value(9).toString();
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

    sortAndLimitFlights(flightList);

    clearAndReloadTable(flightList);

    qDebug() << "航班信息显示完成。";

    closeDatabase();
}


void Special_search::clearAndReloadTable(const QList<QMap<QString, QVariant>> &sortedList) {
    // 清空现有的表格内容
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(sortedList.size());

    int row = 0;
    for (const auto &flight : qAsConst(sortedList)) {
        // 航班号
        QTableWidgetItem *itemDestination = new QTableWidgetItem(flight["destination"].toString());
        ui->tableWidget->setItem(row, 0, itemDestination);

        // 航班号
        QTableWidgetItem *itemFlightNo = new QTableWidgetItem(flight["flightNo"].toString());
        ui->tableWidget->setItem(row, 1, itemFlightNo);

        // 航空公司
        QTableWidgetItem *itemAirline = new QTableWidgetItem(flight["airlineCompanyName"].toString());
        ui->tableWidget->setItem(row, 2, itemAirline);

        // 机型
        QTableWidgetItem *itemAircraft = new QTableWidgetItem(flight["aircraftType"].toString());
        ui->tableWidget->setItem(row, 3, itemAircraft);

        // 起飞时间
        QTableWidgetItem *itemDepartTime = new QTableWidgetItem(flight["departTime"].toTime().toString("hh:mm"));
        ui->tableWidget->setItem(row, 4, itemDepartTime);

        // 出发机场
        QTableWidgetItem *itemDepartPort = new QTableWidgetItem(flight["departPortName"].toString());
        ui->tableWidget->setItem(row, 5, itemDepartPort);

        // 到达时间
        QTableWidgetItem *itemArriveTime = new QTableWidgetItem(flight["arriveTime"].toTime().toString("hh:mm"));
        ui->tableWidget->setItem(row, 6, itemArriveTime);

        // 到达机场
        QTableWidgetItem *itemArrivePort = new QTableWidgetItem(flight["arrivePortName"].toString());
        ui->tableWidget->setItem(row, 7, itemArrivePort);

        // 准点率
        QTableWidgetItem *itemOnTimeRate = new QTableWidgetItem(QString::number(flight["onTimeRate"].toDouble(), 'f', 2) + "%");
        ui->tableWidget->setItem(row, 8, itemOnTimeRate);

        // 票价
        QTableWidgetItem *itemPrice = new QTableWidgetItem(QString::number(flight["price"].toDouble(), 'f', 2));
        ui->tableWidget->setItem(row, 9, itemPrice);

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
        ui->tableWidget->setCellWidget(row, 10, widget);

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
void Special_search::sortFlightList(const QString &key, Qt::SortOrder order) {
    std::sort(flightList.begin(), flightList.end(), [key, order](const QMap<QString, QVariant> &a, const QMap<QString, QVariant> &b) {
        if (key == "departTime") {
            return order == Qt::AscendingOrder ? a[key].toTime() < b[key].toTime() : a[key].toTime() > b[key].toTime();
        } else if (key == "price") {
            return order == Qt::AscendingOrder ? a[key].toDouble() < b[key].toDouble() : a[key].toDouble() > b[key].toDouble();
        }
        return false;  // 默认情况下不排序
    });
}

void Special_search::sortTimeEarly() {
    sortFlightList("departTime", Qt::AscendingOrder);
    clearAndReloadTable(flightList);
}

void Special_search::sortTimeLate() {
    sortFlightList("departTime", Qt::DescendingOrder);
    clearAndReloadTable(flightList);
}

void Special_search::sortPriceLow() {
    sortFlightList("price", Qt::AscendingOrder);
    clearAndReloadTable(flightList);
}

void Special_search::sortPriceHigh() {
    sortFlightList("price", Qt::DescendingOrder);
    clearAndReloadTable(flightList);
}

void Special_search::onRowButtonClicked(int row) {
    // 获取当前行的航班信息
    QMap<QString, QVariant> flight = getFlightInfo(row);

    // 获取查询条件
    QString departCity = getDepartCity();
    // QString arriveCity = getArriveCity();
    QDate date = getDate();

    // 打开子页面并传递航班信息和其他信息
    Customor_DingPao *ding = new Customor_DingPao(flight, departCity, flight["destination"].toString(), date, userAccount);

    this->close();
    ding->show();
}

QMap<QString, QVariant> Special_search::getFlightInfo(int row) {
    // 确保行索引有效
    if (row < 0 || row >= flightList.size()) {
        return QMap<QString, QVariant>();
    }

    // 返回对应行的航班信息
    return flightList[row];
}

QString Special_search::getDepartCity() const {
    return ui->lineEditChu->text();  // 假设出发城市是从组合框中获取的
}


QDate Special_search::getDate() const {
    return ui->dateEdit->date();  // 假设日期是从日期编辑器中获取的
}

void Special_search::on_pushButton_3_clicked()
{
    //返回查询界面
    Flight_sereach* fs=new Flight_sereach(userAccount);
    fs->show();
    delete this;
}

void Special_search::closeEvent(QCloseEvent *event)
{
    emit special_search_closed();
    event->accept();
}

