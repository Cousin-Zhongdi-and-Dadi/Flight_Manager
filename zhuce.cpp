#include "zhuce.h"
#include "ui_zhuce.h"
#include "denglu.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "DatabaseManager.h"
#include <QPainter>
#include <QRegularExpression>

zhuce::zhuce(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::zhuce)
{
    ui->setupUi(this);

    // 设置窗口背景图片
    QPixmap pixmap(":/img/zhuce.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(palette);
    setAutoFillBackground(true);

    // 初始化数据库连接
    QSqlDatabase db = DatabaseManager::instance()->db();
}

zhuce::~zhuce()
{
    delete ui;
}

// 检查指定的账号是否已经存在于数据库中
bool zhuce::checkIfUserExists(const QString &account)
{
    QSqlQuery query;
    query.prepare("SELECT user_account FROM user WHERE user_account = :account");
    query.bindValue(":account", account);

    // 执行查询
    if (!query.exec()) {
        QMessageBox::critical(this, "查询错误", "查询数据库时发生错误");
        return false;
    }

    // 如果查询到记录，说明用户已经存在，返回true
    return query.next();
}

// 向数据库插入新用户信息
bool zhuce::insertUser(const QString &account, const QString &password, const QString &phone, const QString &id, const QString &name)
{
    QSqlQuery query;
    query.prepare("INSERT INTO user (user_account, user_pass, user_phone, user_ID, user_name) "
                  "VALUES (:account, :password, :phone, :id, :name)");
    query.bindValue(":account", account);
    query.bindValue(":password", password);
    query.bindValue(":phone", phone);
    query.bindValue(":id", id);
    query.bindValue(":name", name);

    // 执行插入操作
    if (!query.exec()) {
        QMessageBox::critical(this, "注册失败", "插入数据时发生错误");
        return false;
    }

    // 插入成功返回true
    return true;
}

// 确定按钮点击事件处理
void zhuce::on_pushButton_clicked()
{
    // 当点击确定按钮时执行的操作
    QString account = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString phone = ui->lineEdit_4->text();
    QString id = ui->lineEdit_5->text();
    QString name = ui->lineEdit_6->text();

    // 检查用户是否已经存在
    if (checkIfUserExists(account)) {
        QMessageBox::warning(this, "用户已存在", "该用户已注册");
    } else {
        // 如果用户不存在，尝试插入新用户
        if (insertUser(account, password, phone, id, name)) {
            QMessageBox::information(this, "注册成功", "注册成功，跳转到登录页面");

            // 创建并显示登录窗口，然后关闭当前注册窗口
            denglu *Denglu = new denglu();
            Denglu->show();
            delete this;
        }
    }
}

// 取消按钮点击事件处理
void zhuce::on_pushButton_2_clicked()
{
    // 当点击取消按钮时执行的操作，创建并显示登录窗口，然后关闭当前注册窗口
    denglu *Denglu = new denglu();
    Denglu->show();
    delete this;
}
