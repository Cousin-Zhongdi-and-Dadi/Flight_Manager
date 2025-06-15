#include "denglu.h"
#include "ui_denglu.h"
#include "admin_denglu.h"
#include "zhuce.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QPainter>
#include "DatabaseManager.h"
#include "flight_search.h"

denglu::denglu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::denglu)
{
    ui->setupUi(this);
    QPixmap pixmap=QPixmap(":/img/denglu.png").scaled(this->size());
    QPalette palette;
    //设置主窗口背景图片
    palette.setBrush(QPalette::Window,QBrush(pixmap));

    setPalette(palette);
    setAutoFillBackground(true);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    QSqlDatabase db = DatabaseManager::instance()->db();
}

denglu::~denglu()
{
    delete ui;
}

void denglu::on_loginButton_clicked()
{
    login();
}

void denglu::login(){
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // 判断是否输入了账号和密码
    if (username.isEmpty() || password.isEmpty()) {
        showMessage("请输入用户名和密码！");
        return;
    }
    // 检查用户名和密码是否正确
    if (checkLogin(username, password)) {
        showMessage("登录成功");
        // checkTodaysFlights(username);
        // 登录成功后跳转到查询页面或其他操作
        Flight_sereach *fs = new Flight_sereach(username);


        fs->show();
        this->close();
    } else {
        showMessage("用户名或密码错误！");
    }
}

void denglu:: checkTodaysFlights(const QString &userAccount) {
    // 获取当前日期
    QDate currentDate = QDate::currentDate();

    // 准备SQL查询语句，查找与当前用户账号相关的所有订单
    QSqlQuery query;
    QString sql = "SELECT flightNo, date,departCityName,arriveCityName FROM `order` WHERE user_account = :account";
    query.prepare(sql);
    query.bindValue(":account", userAccount);

    if (!query.exec()) {
        // 处理查询错误
        qDebug() << "查询失败:" << query.lastError();
        return;
    }

    QString flightNumbers;
    QString departCityName;
    QString arriveCityName;
    while (query.next()) {
        // 从查询结果中获取日期和航班号
        QDate orderDate = query.value("date").toDate();
        QString flightNumber = query.value("flightNo").toString();
        qDebug()<<flightNumber;
        // 检查订单日期是否与今天相同
        if (orderDate == currentDate) {
            flightNumbers=flightNumber;
            departCityName=query.value("departCityName").toString();
            arriveCityName=query.value("arriveCityName").toString();
        }
    }

    // 如果有今天的航班，弹出提醒窗口
    if (!flightNumbers.isEmpty()) {
        QString message = "您今天有航班" + flightNumbers + "从" + departCityName + "飞往" + arriveCityName + "，请做好出行准备。";
        QMessageBox::information(nullptr, "今日航班提醒", message);
    } else {
        // 可选：如果没有今天的航班，可以不弹出任何消息或者弹出一条不同的消息
        QMessageBox::information(nullptr, "提示", "您今天没有航班安排。");
    }
}


bool denglu::checkLogin(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT user_pass FROM user WHERE user_account = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qDebug() << "查询错误:" << query.lastError();
        showMessage("查询数据库时发生错误！");
        return false;
    }

    if (query.next()) {
        // 获取数据库中的密码
        QString dbPassword = query.value(0).toString();

        // 比较数据库中的密码和输入的密码
        if (dbPassword == password) {
            return true;  // 登录成功
        } else {
            return false; // 密码错误
        }
    } else {
        return false;  // 用户不存在
    }
}

void denglu::on_showPasswordCheckBox_clicked(bool checked)
{
    if (checked) {
        ui->passwordLineEdit->setEchoMode(QLineEdit::Normal);  // 显示密码
    } else {
        ui->passwordLineEdit->setEchoMode(QLineEdit::Password);  // 隐藏密码
    }
}

void denglu::showMessage(const QString &message)
{
    QMessageBox::information(this, "提示", message);
}

void denglu::on_governorLoginButton_clicked()
{
    denglu_governor *governorLogin = new denglu_governor();
    governorLogin->show();
    this->close();
}

void denglu::on_registerButton_clicked()
{
    zhuce *Zhuce = new zhuce();
    Zhuce->show();
    this->close();
}

