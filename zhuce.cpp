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

// 检查用户输入的有效性
bool zhuce::checkInput()
{
    // 获取用户从界面上输入的各项信息
    QString account = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString confirmPassword = ui->lineEdit_3->text();
    QString phone = ui->lineEdit_4->text();
    QString id = ui->lineEdit_5->text();
    QString name = ui->lineEdit_6->text();

    // 验证所有字段是否都已填写
    if (account.isEmpty() || password.isEmpty() || confirmPassword.isEmpty() || phone.isEmpty() || id.isEmpty() || name.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "请确保所有字段都已填写");
        return false;
    }

    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");

    // 使用正则表达式进行匹配
    if (!emailRegex.match(account).hasMatch()) {
        QMessageBox::warning(nullptr, "邮箱错误", "邮箱格式有误，请重新输入");
        return false;
    }

    // 验证密码和确认密码是否匹配
    if (password != confirmPassword) {
        QMessageBox::warning(this, "密码不一致", "密码和确认密码不一致，请重新输入");
        return false;
    }

    // 手机号码的有效位数
    if (phone.length()!=11||phone[0]!='1'){
        QMessageBox::warning(this, "格式错误", "手机号码输入格式有误，请重新输入");
        return false;
    }

    // 身份证号码的有效位数
    if (id.length()!=18){
        QMessageBox::warning(this, "格式错误", "身份证号码输入格式有误，请重新输入");
        return false;
    }

    // 密码的有效位数
    if (password.length()<=6){
        QMessageBox::warning(this, "格式错误", "密码强度过低，请输入大于六位的密码");
        return false;
    }

    // 检查姓名为汉字
    QString text = name;
    QRegularExpression regExp("[\\p{Han}]+"); // 匹配汉字的正则表达式

    if (!regExp.match(text).hasMatch()) {
        QMessageBox::warning(this, "格式错误", "不支持此姓名，请输入汉字");
        return false;
    }

    // 如果所有检查通过，则返回true
    return true;
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
    if (checkInput()) {  // 首先检查输入是否有效
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
}

// 取消按钮点击事件处理
void zhuce::on_pushButton_2_clicked()
{
    // 当点击取消按钮时执行的操作，创建并显示登录窗口，然后关闭当前注册窗口
    denglu *Denglu = new denglu();
    Denglu->show();
    delete this;
}
