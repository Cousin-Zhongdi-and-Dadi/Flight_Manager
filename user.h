#ifndef USER_H
#define USER_H

#include<QString>

class User
{
public:
    User();
    User(QString account,QString pass,QString id,QString phone,QString name):
        user_account(account),user_pass(pass),user_ID(id),user_phone(phone),user_name(name){};

    QString user_account;
    QString user_pass;
    QString user_ID;
    QString user_phone;
    QString user_name;
};

#endif // USER_H
