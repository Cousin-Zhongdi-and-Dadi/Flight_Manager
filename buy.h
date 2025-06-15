#ifndef BUY_H
#define BUY_H

#include <QWidget>
#include <QMap>
#include <QDateTime>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QCloseEvent>
#include "user_panel.h"

namespace Ui {
class Customor_DingPao;
}

class Customor_DingPao : public QWidget
{
    Q_OBJECT

public:
    explicit Customor_DingPao(const QMap<QString, QVariant> &flight,
                           const QString &departCity,
                           const QString &arriveCity,
                           const QDate &date,
                           const QString &userAccount,
                           QWidget *parent = nullptr);
    ~Customor_DingPao();

    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButtonBack_clicked();

    void on_pushButton_clicked();



private:
    Ui::Customor_DingPao *ui;
    QSqlDatabase db;
    bool openDatabase();
    void closeDatabase();
    void BuyTicket(const QString &name,const QString &ID,const QString &seat);
    QMap<QString, QVariant> thisFlight;
    QDate thisDate;
    QString thisAccount;
    QString departCity;
    QString arriveCity;

    UserPanel userPanel;

signals:
    void customor_dingpao_closed();
};

#endif // BUY_H
