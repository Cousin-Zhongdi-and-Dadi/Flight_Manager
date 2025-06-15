/********************************************************************************
** Form generated from reading UI file 'denglu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DENGLU_H
#define UI_DENGLU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_denglu
{
public:
    QWidget *centralwidget;
    QCheckBox *showPasswordCheckBox;
    QPushButton *registerButton;
    QPushButton *governorLoginButton;
    QLineEdit *usernameLineEdit;
    QPushButton *loginButton;
    QLineEdit *passwordLineEdit;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *denglu)
    {
        if (denglu->objectName().isEmpty())
            denglu->setObjectName("denglu");
        denglu->resize(1000, 600);
        denglu->setMaximumSize(QSize(1060, 611));
        centralwidget = new QWidget(denglu);
        centralwidget->setObjectName("centralwidget");
        showPasswordCheckBox = new QCheckBox(centralwidget);
        showPasswordCheckBox->setObjectName("showPasswordCheckBox");
        showPasswordCheckBox->setGeometry(QRect(170, 350, 171, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213")});
        font.setPointSize(12);
        showPasswordCheckBox->setFont(font);
        showPasswordCheckBox->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(233, 233, 233);"));
        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(620, 290, 81, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213")});
        font1.setPointSize(16);
        registerButton->setFont(font1);
        registerButton->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgba(255, 255, 255, 0);"));
        governorLoginButton = new QPushButton(centralwidget);
        governorLoginButton->setObjectName("governorLoginButton");
        governorLoginButton->setGeometry(QRect(330, 350, 81, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\344\270\255\345\256\213")});
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(true);
        governorLoginButton->setFont(font2);
        governorLoginButton->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(233, 233, 233);"));
        usernameLineEdit = new QLineEdit(centralwidget);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(210, 220, 201, 31));
        QFont font3;
        font3.setPointSize(14);
        usernameLineEdit->setFont(font3);
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(270, 430, 71, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font4.setPointSize(16);
        font4.setBold(false);
        font4.setItalic(false);
        loginButton->setFont(font4);
        loginButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/img/denglu2.png);"));
        passwordLineEdit = new QLineEdit(centralwidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(210, 280, 201, 31));
        passwordLineEdit->setFont(font3);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 140, 171, 41));
        QFont font5;
        font5.setPointSize(16);
        label_3->setFont(font5);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(233, 233, 233);"));
        denglu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(denglu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        denglu->setMenuBar(menubar);
        statusbar = new QStatusBar(denglu);
        statusbar->setObjectName("statusbar");
        denglu->setStatusBar(statusbar);

        retranslateUi(denglu);

        QMetaObject::connectSlotsByName(denglu);
    } // setupUi

    void retranslateUi(QMainWindow *denglu)
    {
        denglu->setWindowTitle(QCoreApplication::translate("denglu", "\347\231\273\345\275\225", nullptr));
        showPasswordCheckBox->setText(QCoreApplication::translate("denglu", "\346\230\276\347\244\272\345\257\206\347\240\201", nullptr));
        registerButton->setText(QString());
        governorLoginButton->setText(QCoreApplication::translate("denglu", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
        loginButton->setText(QString());
        label_3->setText(QCoreApplication::translate("denglu", "<html><head/><body><p>\346\254\242\350\277\216\346\235\245\345\210\260\350\275\257\345\267\245\345\207\272\350\241\214</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class denglu: public Ui_denglu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DENGLU_H
