#ifndef OPENDATABASE_H
#define OPENDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDate>
#include "order.h"

class openDatabase
{
public:
    openDatabase();
    static QSqlDatabase startDatabase();
    static bool insertNewOrderIntoDatabase(const Order &newOrder);
    static bool updateStatusInDatabase(int orderID, int newStatus);
    static bool updateTicketInDatabase(QString date, int eco_seat, int bus_seat, int pri_seat, Order newOrder);
    static bool checkDateAndRefreshDatabase();

    static QDate current_date;
};

#endif // OPENDATABASE_H
