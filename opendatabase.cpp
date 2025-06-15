#include "opendatabase.h"

openDatabase::openDatabase() {
}

QDate openDatabase::current_date=QDate::currentDate();

QSqlDatabase openDatabase::startDatabase()
{
    QSqlDatabase dbcon;
    dbcon = QSqlDatabase::addDatabase("QODBC");  // ODBC 驱动
    dbcon.setHostName("127.0.0.1");                // MySQL 服务器ip地址，本机
    dbcon.setPort(3306);                          // 端口号，默认
    dbcon.setDatabaseName("flight_db");           // ODBC 数据源名称
    bool ok = dbcon.open();
    if(!ok)
        qDebug() << "Error,  数据库文件打开失败！";
    else
        qDebug() << "Sucess, 数据库文件打开成功！";
    return dbcon;
}

bool openDatabase::insertNewOrderIntoDatabase(const Order &newOrder) {
    QSqlQuery query;
    query.prepare("INSERT INTO `order` (user_account, flightNo, date, departCityName, arriveCityName, eco, bus, pri, price, status, departTime, arriveTime, passID, passName) "
                  "VALUES (:user_account, :flightNo, :date, :departCityName, :arriveCityName, :eco, :bus, :pri, :price, :status, :departTime, :arriveTime, :passID, :passName)");
    query.bindValue(":user_account", newOrder.user_account);
    query.bindValue(":flightNo", newOrder.flightNo);
    query.bindValue(":date", newOrder.date);
    query.bindValue(":departCityName", newOrder.departCityName);
    query.bindValue(":arriveCityName", newOrder.arriveCityName);
    query.bindValue(":eco", newOrder.eco);
    query.bindValue(":bus", newOrder.bus);
    query.bindValue(":pri", newOrder.pri);
    query.bindValue(":price", newOrder.price);
    query.bindValue(":status", newOrder.status);
    query.bindValue(":departTime", newOrder.departTime);
    query.bindValue(":arriveTime", newOrder.arriveTime);
    query.bindValue(":passID", newOrder.passID);
    query.bindValue(":passName", newOrder.passName);


    if (!query.exec()) {
        qDebug() << "Insert failed";
        return false;
    }
    return true;
}

bool openDatabase::updateStatusInDatabase(int orderID, int newStatus) {
    QSqlQuery query;
    query.prepare("UPDATE `order` SET status = :newStatus WHERE order_ID = :orderID");
    query.bindValue(":newStatus", newStatus);
    query.bindValue(":orderID", orderID);

    if (!query.exec()) {
        qDebug() << "Update failed";
        return false;
    }
    return true;
}

bool openDatabase::updateTicketInDatabase(QString date, int eco_seat, int bus_seat, int pri_seat, Order newOrder) {
    QSqlQuery query;
    QString sql="UPDATE schedule"+date+" SET";

    if(newOrder.eco){
        sql+=" eco_seat = :new_eco_seat";
    }else if(newOrder.bus){
        sql+=" bus_seat = :new_bus_seat";
    }else if(newOrder.pri){
        sql+=" pri_seat = :new_pri_seat";
    }

    sql+=" WHERE flightNo = :flightNo";

    query.prepare(sql);
    if(newOrder.eco){
        query.bindValue(":new_eco_seat", eco_seat);
    }else if(newOrder.bus){
        query.bindValue(":new_bus_seat", bus_seat);
    }else if(newOrder.pri){
        query.bindValue(":new_pri_seat", pri_seat);
    }
    query.bindValue(":flightNo", newOrder.flightNo);

    if (!query.exec()) {
        qDebug() << "Update failed";
        return false;
    }
    return true;
}

bool openDatabase::checkDateAndRefreshDatabase()
{
    QSqlQuery query;
    QString sql="UPDATE `order` SET status = 4 WHERE date < :date AND status!=2 AND status!=3 AND status!=6";
    query.prepare(sql);
    QString date_str=current_date.toString("yyyy-MM-dd");
    query.bindValue(":date",date_str);
    query.exec();
    while(query.next());
    return true;
}

