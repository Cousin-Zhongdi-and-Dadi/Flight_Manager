#ifndef SPECIAL_SEARCH_H
#define SPECIAL_SEARCH_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QCloseEvent>
// #include <algorithm>
#include "user_panel.h"

namespace Ui {
class Special_search;
}

class Special_search : public QWidget
{
    Q_OBJECT

public:
    explicit Special_search(const QString &userAccount,QWidget *parent = nullptr);
    ~Special_search();

    void closeEvent(QCloseEvent *event);

private slots:

    void on_pushButton_clicked();
    void sortTimeEarly();  // 按起飞时间升序排序
    void sortTimeLate();   // 按起飞时间降序排序
    void sortPriceLow();   // 按票价升序排序
    void sortPriceHigh();  // 按票价降序排序
    void onRowButtonClicked(int row);

    void on_pushButton_3_clicked();

private:
    Ui::Special_search *ui;
    QSqlDatabase db;
    bool openDatabase();
    void closeDatabase();
    void loadFlights(const QString &departCity, const QDate &date);
    // 维护航班列表
    QList<QMap<QString, QVariant>> flightList;

    void sortAndLimitFlights(QList<QMap<QString, QVariant>> &flightList);
    // 清空表格并重新加载数据
    void clearAndReloadTable(const QList<QMap<QString, QVariant>> &sortedList);

    // 根据指定字段对 flightList 进行排序
    void sortFlightList(const QString &key, Qt::SortOrder order);
    // 获取当前行的航班信息
    QMap<QString, QVariant> getFlightInfo(int row);

    // 获取查询条件
    QString getDepartCity() const;
    // QString getArriveCity() const;
    QDate getDate() const;

    // userPanel
    UserPanel userPanel;

    QString userAccount;

signals:
    void special_search_closed();

};

#endif // FLIGHT_SEREACH_H
