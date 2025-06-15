#ifndef USER_PANEL_H
#define USER_PANEL_H

#include <QWidget>
#include <QSqlDatabase>
#include <QVector>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QPalette>
#include <QCloseEvent>
#include "gaiqian.h"
#include "opendatabase.h"
#include "user.h"
#include "info_edit.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class UserPanel;
}
QT_END_NAMESPACE

class UserPanel : public QWidget
{
    Q_OBJECT

public:
    UserPanel(QWidget *parent = nullptr);
    ~UserPanel();
    bool readDataFromDatabase();

    //传入用户信息
    bool receiveUserInfo(QString user_account);
    bool searchUserFromDatabase(QString user_account);
    void closeEvent(QCloseEvent *event);

private slots:
    void on_backwardButton_2_clicked();

    void on_logoutButton_clicked();

private:
    Ui::UserPanel *ui;
    // int user_account=1234;
    // QString user_pass;
    // QString user_ID;
    // QString user_phone;
    // QString user_name;
    customer_GaiQian *customer_gaiqian;
    userInfoEdit *user_info_edit;

    QSqlDatabase dbcon;

    User user;

    void openChangeOrderWidget(const Order &order);

    //bool m_sortAsc;
    //int m_lastSortedColumn;
signals:
    void user_panel_closed();
};

#endif // USER_PANEL_H
