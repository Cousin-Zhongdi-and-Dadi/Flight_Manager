#ifndef ADMIN_PANEL_H
#define ADMIN_PANEL_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "flight_add.h"
#include "Search.h"
#include <QSqlQueryModel>
#include <QTimer>

class FlightManager : public QMainWindow {
    Q_OBJECT

public:

    explicit FlightManager(QWidget *parent = nullptr);

    ~FlightManager() {
        delete ui;
        delete searchWindow;
    }

    bool isAnyFieldEmpty();
private:
    Ui::Form *ui;
    Ui::SearchForm *searchUi; // 保存查询订单界面的 UI 实例
    QWidget *searchWindow; // 查询订单界面的容器
    QSqlDatabase db; // 存储数据库连接

    void initDatabase();

public slots:
    void addFlight();

    void searchOrders();

    void onExitButtonClicked() {
        QApplication::quit();
    }
    void showSearchWindow();

    void hideSearchWindow();
    void jumpSearch();
    void jumpSearch2();
};

#endif // ADMIN_PANEL_H
