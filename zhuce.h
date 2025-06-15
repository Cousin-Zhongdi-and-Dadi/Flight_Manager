#ifndef ZHUCE_H
#define ZHUCE_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class zhuce;
}

class zhuce : public QWidget
{
    Q_OBJECT

public:
    explicit zhuce(QWidget *parent = nullptr);
    ~zhuce();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::zhuce *ui;
    QSqlDatabase db;                 // 数据库连接
    bool checkInput();               // 检查输入的合法性
    bool checkIfUserExists(const QString &account);  // 检查用户是否存在
    bool insertUser(const QString &account, const QString &password, const QString &phone, const QString &id,const QString &name); // 插入用户数据

};

#endif // ZHUCE_H
