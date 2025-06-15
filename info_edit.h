#ifndef INFO_EDIT_H
#define INFO_EDIT_H

#include <QWidget>
#include <QCloseEvent>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include "user.h"

namespace Ui {
class userInfoEdit;
}

class userInfoEdit : public QWidget
{
    Q_OBJECT

public:
    explicit userInfoEdit(QWidget *parent = nullptr);
    ~userInfoEdit();

    void closeEvent(QCloseEvent *event);

    bool receiveUserFromUserPanel(User user);
private:
    Ui::userInfoEdit *ui;

    User user;

signals:
    void user_info_edit_closed();
};

#endif // INFO_EDIT_H
