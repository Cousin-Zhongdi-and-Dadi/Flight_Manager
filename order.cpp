#include "order.h"

// 打印Order对象信息（可用于调试）
void Order::printOrder() {
    qDebug() << "-----------------------------";
    qDebug() << "订单详情:";
    qDebug() << "订单号: " << order_ID;
    qDebug() << "用户账号: " << user_account;
    qDebug() << "航班号: " << flightNo;
    qDebug() << "日期: " << date;
    qDebug() << "出发城市: " << departCityName;
    qDebug() << "到达城市: " << arriveCityName;
    qDebug() << "舱位: "
             << (eco ? "经济舱" : "")
             << (bus ? "商务舱" : "")
             << (pri ? "头等舱" : "");
    qDebug() << "价格: " << price;
    qDebug() << "状态: "
             << (status == 1 ? "正常" :
                     status == 2 ? "改签" :
                     status == 3 ? "退票" : "未知");
    qDebug() << "出发时间: " << departTime;
    qDebug() << "到达时间: " << arriveTime;
    qDebug() << "乘客身份证号: " << passID;
    qDebug() << "乘客姓名: " << passName;
    qDebug() << "-----------------------------";
}
