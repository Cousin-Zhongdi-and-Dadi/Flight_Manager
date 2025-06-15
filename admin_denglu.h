#ifndef ADMIN_DENGLU_H
#define ADMIN_DENGLU_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
namespace Ui {
class denglu_governor;
}

class denglu_governor : public QWidget
{
    Q_OBJECT

public:
    explicit denglu_governor(QWidget *parent = nullptr);
    ~denglu_governor();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::denglu_governor *ui;
    bool verifyLogin(const QString &account, const QString &password);  // 验证账号和密码

};

#endif // ADMIN_DENGLU_H
