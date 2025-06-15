#ifndef DENGLU_H
#define DENGLU_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui {
class denglu;
}
QT_END_NAMESPACE

class denglu : public QMainWindow
{
    Q_OBJECT

public:
    denglu(QWidget *parent = nullptr);
    ~denglu();

private slots:
    void on_loginButton_clicked();

    void on_showPasswordCheckBox_clicked(bool checked);

    void on_governorLoginButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::denglu *ui;

    QSqlDatabase db;  // 数据库连接

    void login();  // 登录函数
    void showMessage(const QString &message);  // 显示消息
    bool checkLogin(const QString &username, const QString &password);  // 检查登录

    void checkTodaysFlights(const QString &userAccount);

};
#endif // DENGLU_H
