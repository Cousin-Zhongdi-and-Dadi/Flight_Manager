/********************************************************************************
** Form generated from reading UI file 'userpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPANEL_H
#define UI_USERPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserPanel
{
public:
    QTableWidget *userOrderTable;
    QLabel *nameLabel;
    QLabel *accountLabel;
    QPushButton *backwardButton;
    QLabel *iconLabel;
    QLabel *phoneLabel;
    QLabel *ID_Label;
    QPushButton *backwardButton_2;
    QPushButton *changePersonInfoButton;
    QPushButton *logoutButton;
    QPushButton *refreshButton;

    void setupUi(QWidget *UserPanel)
    {
        if (UserPanel->objectName().isEmpty())
            UserPanel->setObjectName("UserPanel");
        UserPanel->resize(1061, 611);
        userOrderTable = new QTableWidget(UserPanel);
        userOrderTable->setObjectName("userOrderTable");
        userOrderTable->setGeometry(QRect(20, 300, 1021, 281));
        userOrderTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        nameLabel = new QLabel(UserPanel);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setGeometry(QRect(170, 120, 171, 51));
        QFont font;
        font.setPointSize(16);
        nameLabel->setFont(font);
        accountLabel = new QLabel(UserPanel);
        accountLabel->setObjectName("accountLabel");
        accountLabel->setGeometry(QRect(170, 170, 171, 51));
        accountLabel->setFont(font);
        backwardButton = new QPushButton(UserPanel);
        backwardButton->setObjectName("backwardButton");
        backwardButton->setGeometry(QRect(20, 20, 80, 24));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        backwardButton->setFont(font1);
        backwardButton->setCursor(QCursor(Qt::ArrowCursor));
        backwardButton->setMouseTracking(true);
        backwardButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: none; border-radius: 3px; color: black; } \n"
"QPushButton:hover { background-color:rgb(233, 182, 163); }\n"
""));
        iconLabel = new QLabel(UserPanel);
        iconLabel->setObjectName("iconLabel");
        iconLabel->setGeometry(QRect(50, 120, 111, 101));
        phoneLabel = new QLabel(UserPanel);
        phoneLabel->setObjectName("phoneLabel");
        phoneLabel->setGeometry(QRect(350, 120, 421, 51));
        phoneLabel->setFont(font);
        ID_Label = new QLabel(UserPanel);
        ID_Label->setObjectName("ID_Label");
        ID_Label->setGeometry(QRect(350, 170, 531, 51));
        ID_Label->setFont(font);
        backwardButton_2 = new QPushButton(UserPanel);
        backwardButton_2->setObjectName("backwardButton_2");
        backwardButton_2->setGeometry(QRect(950, 20, 80, 24));
        backwardButton_2->setFont(font1);
        backwardButton_2->setCursor(QCursor(Qt::ArrowCursor));
        backwardButton_2->setMouseTracking(true);
        backwardButton_2->setStyleSheet(QString::fromUtf8("QPushButton { background-color: none; border-radius: 3px; color: black; } \n"
"QPushButton:hover { background-color:rgb(233, 182, 163); }\n"
""));
        changePersonInfoButton = new QPushButton(UserPanel);
        changePersonInfoButton->setObjectName("changePersonInfoButton");
        changePersonInfoButton->setGeometry(QRect(170, 230, 131, 28));
        logoutButton = new QPushButton(UserPanel);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(950, 60, 80, 24));
        logoutButton->setFont(font1);
        logoutButton->setCursor(QCursor(Qt::ArrowCursor));
        logoutButton->setMouseTracking(true);
        logoutButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: none; border-radius: 3px; color: black; } \n"
"QPushButton:hover { background-color:rgb(233, 182, 163); }\n"
""));
        refreshButton = new QPushButton(UserPanel);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(350, 230, 131, 28));

        retranslateUi(UserPanel);

        QMetaObject::connectSlotsByName(UserPanel);
    } // setupUi

    void retranslateUi(QWidget *UserPanel)
    {
        UserPanel->setWindowTitle(QCoreApplication::translate("UserPanel", "UserPanel", nullptr));
        nameLabel->setText(QCoreApplication::translate("UserPanel", "\345\247\223\345\220\215\357\274\232", nullptr));
        accountLabel->setText(QCoreApplication::translate("UserPanel", "\350\264\246\345\217\267\357\274\232", nullptr));
        backwardButton->setText(QCoreApplication::translate("UserPanel", "<-\350\277\224\345\233\236", nullptr));
        iconLabel->setText(QCoreApplication::translate("UserPanel", "user_icon", nullptr));
        phoneLabel->setText(QCoreApplication::translate("UserPanel", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        ID_Label->setText(QCoreApplication::translate("UserPanel", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", nullptr));
        backwardButton_2->setText(QCoreApplication::translate("UserPanel", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
        changePersonInfoButton->setText(QCoreApplication::translate("UserPanel", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        logoutButton->setText(QCoreApplication::translate("UserPanel", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        refreshButton->setText(QCoreApplication::translate("UserPanel", "\345\210\267\346\226\260\350\256\242\345\215\225\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserPanel: public Ui_UserPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPANEL_H
