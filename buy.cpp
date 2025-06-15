#include "buy.h"
#include "ui_buy.h"
#include "flight_search.h"
#include <QUuid>
#include <QMessageBox>


Customor_DingPao::Customor_DingPao(const QMap<QString, QVariant> &flight,
                                   const QString &departCity,
                                   const QString &arriveCity,
                                   const QDate &date,
                                   const QString &userAccount,
                                   QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Customor_DingPao),
    thisFlight(flight),
    thisDate(date),
    thisAccount(userAccount),
    departCity(departCity),
    arriveCity(arriveCity)
{
    ui->setupUi(this);

    // 设置窗口背景图片
    QPixmap pixmap(":/img/panel.png");
    pixmap = pixmap.scaled(1061, 611, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(palette);
    setAutoFillBackground(true);

    // 设置航班详细信息
    ui->lineEditDate->setText(date.toString("yyyy-MM-dd"));
    ui->lineEditCode->setText(flight["flightNo"].toString());
    ui->lineEditLauTime->setText(flight["departTime"].toTime().toString("hh:mm"));
    ui->lineEditArrTime->setText(flight["arriveTime"].toTime().toString("hh:mm"));
    ui->lineEditLauPort->setText(flight["departPortName"].toString());
    ui->lineEditArrPort->setText(flight["arrivePortName"].toString());
    ui->lineEditLauCity->setText(departCity);
    ui->lineEditArrCity->setText(arriveCity);

    ui->lineEditPrice1->setText(QString::number(flight["price"].toDouble(), 'f', 2));
    ui->lineEditPrice2->setText(QString::number(flight["price"].toDouble() * 2, 'f', 2));
    ui->lineEditPrice3->setText(QString::number(flight["price"].toDouble() * 4, 'f', 2));
    \
    ui->lineEditAccount->setText(userAccount);
    ui->lineEditName->setPlaceholderText("输入姓名");
    ui->lineEditSfz->setPlaceholderText("输入证件号");

    QString currentText = ui->seat->currentText();
    qDebug() << "当前选中的内容：" << currentText;
}

Customor_DingPao::~Customor_DingPao()
{
    delete ui;
}

//返回按钮
void Customor_DingPao::on_pushButtonBack_clicked()
{
    //返回查询界面
    Flight_sereach* fs=new Flight_sereach(thisAccount);
    fs->show();
    delete this;

}

//搜索按钮槽函数
void Customor_DingPao::on_pushButton_clicked()
{

    // 检查输入是否为空
    QString name = ui->lineEditName->text().trimmed();
    QString ID = ui->lineEditSfz->text().trimmed();
    QString seat = ui->seat->currentText();
    if (name.isEmpty() || ID.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "姓名和身份证不能为空！");
        return;
    }

    QRegularExpression regExp("[\\p{Han}]+"); // 匹配汉字的正则表达式

    if (!regExp.match(name).hasMatch()) {
        QMessageBox::warning(this, "格式错误", "不支持此姓名，请输入汉字");
        return;
    }


    // 身份证号码的有效位数
    if (ID.length()!=18){
        QMessageBox::warning(this, "格式错误", "身份证号码输入格式有误，请重新输入");
        return;
    }

    // 加载航班信息
    BuyTicket(name, ID ,seat);

}

//打开数据库
bool Customor_DingPao::openDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost"); // MySQL服务器地址
    db.setDatabaseName("flight_db"); // 数据库名
    db.setUserName("root"); // 用户名
    db.setPassword("123456"); // 密码

    if (!db.open()) {
        QMessageBox::critical(this, "无法打开数据库", db.lastError().text());
        return false;
    }
    return true;
}

//关闭数据库
void Customor_DingPao::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}


void Customor_DingPao::BuyTicket(const QString &name,const QString &ID,const QString &seat){
    // 打开数据库连接
    if (!openDatabase()) {
        return;
    }

    QString scheduleTableName = "schedule" + thisDate.toString("yyyyMMdd");

    QSqlQuery query;
    query.prepare(QString("SELECT eco_seat, bus_seat, pri_seat FROM %1 WHERE flightNo = :flightNo").arg(scheduleTableName));
    query.bindValue(":flightNo", thisFlight["flightNo"]);

    if (!query.exec()) {
        QMessageBox::critical(this, "查询失败", query.lastError().text());
        closeDatabase();
        return;
    }
    // 创建一个列表来存储座位信息
    QList<int> seatCounts;
    if (query.next()) {

        seatCounts << query.value(0).toInt()  // eco_seat
                   << query.value(1).toInt()  // bus_seat
                   << query.value(2).toInt(); // pri_seat

    }


    if(seat=="经济舱")
    {
        qDebug() << "Economy Class Seats:" << seatCounts[0];
        if(seatCounts[0]==0){
            QMessageBox::critical(this, "警告", "经济舱无余票");
            closeDatabase();
            return;
        }
        QString scheduleTableName = "schedule" + thisDate.toString("yyyyMMdd");
        QSqlQuery query;
        query.prepare(QString("UPDATE %1 SET eco_seat = eco_seat - 1 WHERE flightNo = :flightNo").arg(scheduleTableName));
        query.bindValue(":flightNo", thisFlight["flightNo"]);
        if (!query.exec()) {
            qDebug() << "Update schedule failed:" << query.lastError();
        }

        query.prepare("INSERT INTO `order` (`user_account`, `flightNo`, `date`, `departCityName`, `arriveCityName`, "
                      "`eco`, `bus`, `pri`, `price`, `status`, `departTime`, `arriveTime`, `passName`, `passID`) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

        // 绑定值，确保每个占位符都有对应的值
        query.addBindValue(thisAccount);
        query.addBindValue(thisFlight["flightNo"].toString());
        query.addBindValue(thisDate.toString("yyyy-MM-dd"));
        query.addBindValue(departCity);
        query.addBindValue(arriveCity);
        query.addBindValue(true);                              // 经济舱
        query.addBindValue(false);                             // 商务舱
        query.addBindValue(false);                             // 头等舱
        query.addBindValue(thisFlight["price"].toDouble());    // 直接传递 double 值
        query.addBindValue(1);                                 // 状态
        query.addBindValue(thisFlight["departTime"].toTime().toString("HH:mm:ss"));
        query.addBindValue(thisFlight["arriveTime"].toTime().toString("HH:mm:ss"));

        query.addBindValue(name);                              // 乘客姓名
        query.addBindValue(ID);                                // 乘客身份证号

        if (!query.exec()) {
            qDebug() << "Insert order record failed:" << query.lastError();
        }
        QMessageBox::information(nullptr, "订票成功", QString().asprintf("您需支付 %.2f 元", thisFlight["price"].toDouble()));
    }

    if(seat=="商务舱")
    {
        qDebug() << "Business Class Seats:" << seatCounts[1];
        if(seatCounts[1]==0){
            QMessageBox::critical(this, "警告","商务舱无余票");
            closeDatabase();
            return;
        }
        QString scheduleTableName = "schedule" + thisDate.toString("yyyyMMdd");
        QSqlQuery query;
        query.prepare(QString("UPDATE %1 SET bus_seat = bus_seat - 1 WHERE flightNo = :flightNo").arg(scheduleTableName));
        query.bindValue(":flightNo", thisFlight["flightNo"]);
        if (!query.exec()) {
            qDebug() << "Update schedule failed:" << query.lastError();
        }

        query.prepare("INSERT INTO `order` (`user_account`, `flightNo`, `date`, `departCityName`, `arriveCityName`, "
                      "`eco`, `bus`, `pri`, `price`, `status`, `departTime`, `arriveTime`, `passName`, `passID`) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

        // 绑定值，确保每个占位符都有对应的值
        query.addBindValue(thisAccount);
        query.addBindValue(thisFlight["flightNo"].toString());
        query.addBindValue(thisDate.toString("yyyy-MM-dd"));
        query.addBindValue(departCity);
        query.addBindValue(arriveCity);
        query.addBindValue(false);                              // 经济舱
        query.addBindValue(true);                             // 商务舱
        query.addBindValue(false);                             // 头等舱
        query.addBindValue(thisFlight["price"].toDouble()*2);    // 直接传递 double 值
        query.addBindValue(1);                                 // 状态
        query.addBindValue(thisFlight["departTime"].toTime().toString("HH:mm:ss"));
        query.addBindValue(thisFlight["arriveTime"].toTime().toString("HH:mm:ss"));

        query.addBindValue(name);                              // 乘客姓名
        query.addBindValue(ID);                                // 乘客身份证号

        if (!query.exec()) {
            qDebug() << "Insert order record failed:" << query.lastError();
        }
        QMessageBox::information(nullptr, "订票成功", QString().asprintf("您需支付 %.2f 元", thisFlight["price"].toDouble()*2));

    }
    if(seat=="头等舱")
    {
        qDebug() << "First Class Seats:" << seatCounts[2];
        if(seatCounts[2]==0){
            QMessageBox::critical(this, "警告","头等舱无余票");
            closeDatabase();
            return;
        }
        QString scheduleTableName = "schedule" + thisDate.toString("yyyyMMdd");
        QSqlQuery query;
        query.prepare(QString("UPDATE %1 SET pri_seat = pri_seat - 1 WHERE flightNo = :flightNo").arg(scheduleTableName));
        query.bindValue(":flightNo", thisFlight["flightNo"]);
        if (!query.exec()) {
            qDebug() << "Update schedule failed:" << query.lastError();
        }

        query.prepare("INSERT INTO `order` (`user_account`, `flightNo`, `date`, `departCityName`, `arriveCityName`, "
                      "`eco`, `bus`, `pri`, `price`, `status`, `departTime`, `arriveTime`, `passName`, `passID`) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

        // 绑定值，确保每个占位符都有对应的值
        query.addBindValue(thisAccount);
        query.addBindValue(thisFlight["flightNo"].toString());
        query.addBindValue(thisDate.toString("yyyy-MM-dd"));
        query.addBindValue(departCity);
        query.addBindValue(arriveCity);
        query.addBindValue(false);                              // 经济舱
        query.addBindValue(false);                             // 商务舱
        query.addBindValue(true);                             // 头等舱
        query.addBindValue(thisFlight["price"].toDouble()*4);    // 直接传递 double 值
        query.addBindValue(1);                                 // 状态
        query.addBindValue(thisFlight["departTime"].toTime().toString("HH:mm:ss"));
        query.addBindValue(thisFlight["arriveTime"].toTime().toString("HH:mm:ss"));

        query.addBindValue(name);                              // 乘客姓名
        query.addBindValue(ID);                                // 乘客身份证号

        if (!query.exec()) {
            qDebug() << "Insert order record failed:" << query.lastError();
        }
        QMessageBox::information(nullptr, "订票成功", QString().asprintf("您需支付 %.2f 元", thisFlight["price"].toDouble()*4));
    }


    //返回查询界面
    Flight_sereach* fs=new Flight_sereach(thisAccount);
    fs->show();
    delete this;
}

void Customor_DingPao::closeEvent(QCloseEvent *event)
{
    emit customor_dingpao_closed();
    event->accept();
}
