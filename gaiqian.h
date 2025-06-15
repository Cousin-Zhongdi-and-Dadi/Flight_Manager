#ifndef GAIQIAN_H
#define GAIQIAN_H

#include <QWidget>
#include <QTableWidget>
#include <QString>
#include <QTableWidgetItem>
#include <qstackedwidget.h>
#include <QMessageBox>
#include <QtGlobal>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>
#include <QDate>
#include <QMessageBox>
#include <QCloseEvent>
#include "order.h"
#include "opendatabase.h"

namespace Ui {
class customer_GaiQian;
}

class customer_GaiQian : public QWidget
{
    Q_OBJECT

public:
    explicit customer_GaiQian(QWidget *parent = nullptr);
    ~customer_GaiQian();

    void receiveOrder(const Order order,const QSqlDatabase &dbcon);

    void showDatabase();

    void closeEvent(QCloseEvent *event);
    //void refreshDatabaseFromNewOrder(int rowCount, int remain_eco, int remain_bus, int remain_pri, QStringList date);
//public slots:
//    void onSortByColumn(int col);
    void refreshDatabaseFromNewOrder(int rowCount, int remain_eco, int remain_bus, int remain_pri, QStringList date, Order newOrder);
private:
    Ui::customer_GaiQian *ui;
    Order current_order;
    QSqlDatabase dbcon;

    int current_eco;
    int current_bus;
    int current_pri;

    QString origin_date;

    //bool m_sortAsc;
    //int m_lastSortedColumn;

    bool has_validTickets;

    QDate today;
signals:
    void customer_gaiqian_closed();
};

#endif // GAIQIAN_H
