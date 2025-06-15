#include "info_edit.h"
#include "ui_info_edit.h"
#include <QRegularExpression>

// 构造函数
userInfoEdit::userInfoEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userInfoEdit)
{
    ui->setupUi(this);

    // 设置窗口固定大小和标题
    setFixedSize(530, 300);
    setWindowTitle("修改个人信息");

    // 初始化界面控件内容
    ui->userAccountEdit->setText(user.user_account);
    ui->userPassEdit->setText("");
    ui->userID_Edit->setText(user.user_ID);
    ui->userNameEdit->setText(user.user_name);
    ui->userPhoneEdit->setText(user.user_phone);

    // 连接“确认修改”按钮点击事件
    connect(ui->confirmEdit, &QPushButton::clicked, [=]() {
        if (!ui->userPassEdit->text().isEmpty()&&ui->userPassEdit->text().length() <= 6) {
            QMessageBox::warning(this, "修改失败", "密码位数过短");
            return;
        }
        // 校验手机号码格式
        QString phone=ui->userPhoneEdit->text();
        //qDebug()<<phone;
        if (phone.length() != 11||phone[0]!='1') {
            QMessageBox::warning(this, "修改失败", "手机号码格式错误");
            return;
        }

        // 校验身份证号码格式
        if (ui->userID_Edit->text().length() != 18) {
            QMessageBox::warning(this, "修改失败", "身份证号码格式错误");
            return;
        }

        // 检查姓名为汉字
        QString text = ui->userNameEdit->text();
        QRegularExpression regExp("[\\p{Han}]+"); // 匹配汉字的正则表达式

        if (!regExp.match(text).hasMatch()) {
            QMessageBox::warning(this, "修改失败", "不支持此姓名，请输入汉字");
            return;
        }

        // 更新用户对象属性
        user.user_ID = ui->userID_Edit->text();
        user.user_name = ui->userNameEdit->text();
        if (!ui->userPassEdit->text().isEmpty()) {  // 如果密码字段不为空，则更新密码
            user.user_pass = ui->userPassEdit->text();
        }
        user.user_phone = ui->userPhoneEdit->text();

        // 准备SQL更新语句
        QSqlQuery query;
        query.prepare("UPDATE user SET user_pass = :user_pass, user_ID = :user_ID, "
                      "user_name = :user_name, user_phone = :user_phone "
                      "WHERE user_account = :user_account");

        // 绑定参数值
        query.bindValue(":user_pass", user.user_pass);
        query.bindValue(":user_ID", user.user_ID);
        query.bindValue(":user_name", user.user_name);
        query.bindValue(":user_phone", user.user_phone);
        query.bindValue(":user_account", user.user_account);

        // 执行更新操作
        if (!query.exec()) {
            qDebug() << "Update failed";
            return;
        } else {
            // 显示成功提示并关闭窗口
            QMessageBox::information(this, "成功", "修改成功");
            this->close();
        }
    });

    // 连接“取消修改”按钮点击事件
    connect(ui->cancelEdit, &QPushButton::clicked, [=]() {
        this->close();
    });
}

// 析构函数
userInfoEdit::~userInfoEdit()
{
    delete ui;
}

// 处理窗口关闭事件，发出信号通知其他组件
void userInfoEdit::closeEvent(QCloseEvent *event)
{
    emit user_info_edit_closed();
    event->accept();
}

// 接收来自UserPanel的用户信息并更新界面
bool userInfoEdit::receiveUserFromUserPanel(User user) {
    this->user = user;

    // 更新界面控件内容
    ui->userAccountEdit->setText(user.user_account);
    ui->userPassEdit->setText("");  // 密码字段默认为空
    ui->userID_Edit->setText(user.user_ID);
    ui->userNameEdit->setText(user.user_name);
    ui->userPhoneEdit->setText(user.user_phone);

    return true;
}
