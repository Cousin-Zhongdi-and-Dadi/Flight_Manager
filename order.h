#ifndef ORDER_H
#define ORDER_H
#include <QString>
#include <QDebug>

class Order {
public:
    // 默认构造函数
    Order() = default;

    // 带参数的构造函数
    Order(int orderID, const QString& userAccount, const QString& flightNo, const QString& date,
          const QString& departCityName, const QString& arriveCityName, bool eco, bool bus, bool pri,
          double price, int status)
        : order_ID(orderID), user_account(userAccount), flightNo(flightNo), date(date),
        departCityName(departCityName), arriveCityName(arriveCityName), eco(eco), bus(bus), pri(pri),
        price(price), status(status) {}

    // 成员变量
    int order_ID;  // 订单号
    QString user_account;  // 用户账号
    QString flightNo;  // 航班号
    QString date;  // 日期
    QString departCityName;  // 出发城市名称
    QString arriveCityName;  // 到达城市名称
    bool eco;  // 经济舱
    bool bus;  // 商务舱
    bool pri;  // 头等舱
    double price;  // 价格
    int status;  // 状态：1表示正常，2表示改签，3表示退票
    QString departTime;
    QString arriveTime;
    QString passID;
    QString passName;

    void printOrder();
};

#endif // ORDER_H
