#include "admin_denglu.h"
#include "denglu.h"
#include "ui_admin_denglu.h"
#include <QMessageBox>
#include "DatabaseManager.h"
#include "admin_panel.h"
#include <QPainter>

denglu_governor::denglu_governor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::denglu_governor)
{
    ui->setupUi(this);
    QPixmap pixmap(":/img/zhuce.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(palette);
    setAutoFillBackground(true);
    QSqlDatabase db = DatabaseManager::instance()->db();
}

denglu_governor::~denglu_governor()
{
    delete ui;
}

bool denglu_governor::verifyLogin(const QString &account, const QString &password)
{

    QSqlQuery query;
    query.prepare("SELECT admin_pass FROM admin WHERE admin_account = :account");
    query.bindValue(":account", account);
    if (!query.exec()) {
        qDebug() << "SQL error: " << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString storedPassword = query.value(0).toString();
        if (storedPassword == password) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void denglu_governor::on_pushButton_clicked()
{
    QString account = ui->lineEdit->text();     // 获取账号
    QString password = ui->lineEdit_2->text();  // 获取密码

    // 判断是否输入了账号和密码
    if (account.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "账号或密码不能为空！");
        return;
    }

    // 验证登录
    if (verifyLogin(account, password)) {
        QMessageBox::information(this, "登录成功", "欢迎进入管理员页面！");
        // 跳转到管理员页面
        FlightManager *fm=new FlightManager();
        fm->show();
        delete this;
    } else {
        QMessageBox::warning(this, "登录失败", "账号或密码错误，或该账号不存在！");
    }
}


void denglu_governor::on_pushButton_2_clicked()
{

    denglu *Denglu = new denglu();
    Denglu->show();
    delete this;
}

