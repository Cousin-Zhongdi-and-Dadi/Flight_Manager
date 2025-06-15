/********************************************************************************
** Form generated from reading UI file 'admin_denglu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_DENGLU_H
#define UI_ADMIN_DENGLU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_denglu_governor
{
public:
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;

    void setupUi(QWidget *denglu_governor)
    {
        if (denglu_governor->objectName().isEmpty())
            denglu_governor->setObjectName("denglu_governor");
        denglu_governor->resize(1000, 600);
        denglu_governor->setAutoFillBackground(false);
        label_2 = new QLabel(denglu_governor);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 190, 51, 31));
        pushButton_2 = new QPushButton(denglu_governor);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(360, 370, 81, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label = new QLabel(denglu_governor);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 80, 131, 61));
        label_3 = new QLabel(denglu_governor);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 280, 51, 31));
        lineEdit = new QLineEdit(denglu_governor);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 180, 271, 41));
        QFont font;
        font.setPointSize(14);
        lineEdit->setFont(font);
        pushButton = new QPushButton(denglu_governor);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 370, 81, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        lineEdit_2 = new QLineEdit(denglu_governor);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(200, 280, 271, 41));
        lineEdit_2->setFont(font);

        retranslateUi(denglu_governor);

        QMetaObject::connectSlotsByName(denglu_governor);
    } // setupUi

    void retranslateUi(QWidget *denglu_governor)
    {
        denglu_governor->setWindowTitle(QCoreApplication::translate("denglu_governor", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
        label_2->setText(QCoreApplication::translate("denglu_governor", "<html><head/><body><p><span style=\" font-size:18pt;\">\350\264\246\345\217\267</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("denglu_governor", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("denglu_governor", "<html><head/><body><p><span style=\" font-size:18pt; font-style:italic;\">\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("denglu_governor", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\257\206\347\240\201</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("denglu_governor", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class denglu_governor: public Ui_denglu_governor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_DENGLU_H
