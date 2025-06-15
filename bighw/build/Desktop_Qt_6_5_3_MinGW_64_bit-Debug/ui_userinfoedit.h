/********************************************************************************
** Form generated from reading UI file 'userinfoedit.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFOEDIT_H
#define UI_USERINFOEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userInfoEdit
{
public:
    QLineEdit *userAccountEdit;
    QLineEdit *userPassEdit;
    QLineEdit *userNameEdit;
    QLineEdit *userID_Edit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *userPhoneEdit;
    QLabel *label_5;
    QPushButton *confirmEdit;
    QPushButton *cancelEdit;

    void setupUi(QWidget *userInfoEdit)
    {
        if (userInfoEdit->objectName().isEmpty())
            userInfoEdit->setObjectName("userInfoEdit");
        userInfoEdit->resize(530, 300);
        userAccountEdit = new QLineEdit(userInfoEdit);
        userAccountEdit->setObjectName("userAccountEdit");
        userAccountEdit->setGeometry(QRect(130, 30, 351, 27));
        userAccountEdit->setReadOnly(true);
        userPassEdit = new QLineEdit(userInfoEdit);
        userPassEdit->setObjectName("userPassEdit");
        userPassEdit->setGeometry(QRect(130, 70, 351, 27));
        userNameEdit = new QLineEdit(userInfoEdit);
        userNameEdit->setObjectName("userNameEdit");
        userNameEdit->setGeometry(QRect(130, 110, 351, 27));
        userID_Edit = new QLineEdit(userInfoEdit);
        userID_Edit->setObjectName("userID_Edit");
        userID_Edit->setGeometry(QRect(130, 150, 351, 27));
        label = new QLabel(userInfoEdit);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 30, 51, 19));
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_2 = new QLabel(userInfoEdit);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 70, 51, 19));
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_3 = new QLabel(userInfoEdit);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 110, 51, 19));
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_4 = new QLabel(userInfoEdit);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 150, 81, 19));
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        userPhoneEdit = new QLineEdit(userInfoEdit);
        userPhoneEdit->setObjectName("userPhoneEdit");
        userPhoneEdit->setGeometry(QRect(130, 190, 351, 27));
        label_5 = new QLabel(userInfoEdit);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 190, 71, 19));
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        confirmEdit = new QPushButton(userInfoEdit);
        confirmEdit->setObjectName("confirmEdit");
        confirmEdit->setGeometry(QRect(150, 240, 92, 28));
        cancelEdit = new QPushButton(userInfoEdit);
        cancelEdit->setObjectName("cancelEdit");
        cancelEdit->setGeometry(QRect(310, 240, 92, 28));

        retranslateUi(userInfoEdit);

        QMetaObject::connectSlotsByName(userInfoEdit);
    } // setupUi

    void retranslateUi(QWidget *userInfoEdit)
    {
        userInfoEdit->setWindowTitle(QCoreApplication::translate("userInfoEdit", "Form", nullptr));
        label->setText(QCoreApplication::translate("userInfoEdit", "\350\264\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("userInfoEdit", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("userInfoEdit", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("userInfoEdit", "\350\272\253\344\273\275\350\257\201\345\217\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("userInfoEdit", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        confirmEdit->setText(QCoreApplication::translate("userInfoEdit", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        cancelEdit->setText(QCoreApplication::translate("userInfoEdit", "\345\217\226\346\266\210\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userInfoEdit: public Ui_userInfoEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFOEDIT_H
