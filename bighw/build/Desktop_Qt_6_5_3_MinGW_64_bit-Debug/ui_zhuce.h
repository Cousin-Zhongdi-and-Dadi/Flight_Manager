/********************************************************************************
** Form generated from reading UI file 'zhuce.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZHUCE_H
#define UI_ZHUCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zhuce
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QLineEdit *lineEdit_5;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *lineEdit_6;

    void setupUi(QWidget *zhuce)
    {
        if (zhuce->objectName().isEmpty())
            zhuce->setObjectName("zhuce");
        zhuce->resize(1000, 600);
        lineEdit = new QLineEdit(zhuce);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(250, 110, 261, 31));
        QFont font;
        font.setPointSize(14);
        lineEdit->setFont(font);
        label = new QLabel(zhuce);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 110, 71, 31));
        QFont font1;
        font1.setPointSize(18);
        label->setFont(font1);
        label_3 = new QLabel(zhuce);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 240, 151, 31));
        lineEdit_2 = new QLineEdit(zhuce);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(250, 180, 261, 31));
        lineEdit_2->setFont(font);
        lineEdit_4 = new QLineEdit(zhuce);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(250, 300, 261, 31));
        lineEdit_4->setFont(font);
        label_4 = new QLabel(zhuce);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(140, 300, 101, 31));
        lineEdit_5 = new QLineEdit(zhuce);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(250, 360, 261, 31));
        lineEdit_5->setFont(font);
        label_2 = new QLabel(zhuce);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 180, 71, 31));
        lineEdit_3 = new QLineEdit(zhuce);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(250, 240, 261, 31));
        lineEdit_3->setFont(font);
        label_6 = new QLabel(zhuce);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(290, 40, 101, 41));
        pushButton = new QPushButton(zhuce);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 480, 81, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        pushButton_2 = new QPushButton(zhuce);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(360, 480, 81, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Microsoft YaHei UI\";"));
        label_5 = new QLabel(zhuce);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(160, 360, 71, 31));
        label_7 = new QLabel(zhuce);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(180, 420, 91, 31));
        lineEdit_6 = new QLineEdit(zhuce);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(250, 420, 261, 31));
        lineEdit_6->setFont(font);

        retranslateUi(zhuce);

        QMetaObject::connectSlotsByName(zhuce);
    } // setupUi

    void retranslateUi(QWidget *zhuce)
    {
        zhuce->setWindowTitle(QCoreApplication::translate("zhuce", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("zhuce", "<html><head/><body><p>\351\202\256\347\256\261</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("zhuce", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("zhuce", "<html><head/><body><p><span style=\" font-size:18pt;\">\347\224\265\350\257\235\345\217\267\347\240\201</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("zhuce", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\257\206\347\240\201</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("zhuce", "<html><head/><body><p><span style=\" font-size:16pt; font-style:italic;\">\347\224\250\346\210\267\346\263\250\345\206\214</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("zhuce", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("zhuce", "\350\277\224\345\233\236", nullptr));
        label_5->setText(QCoreApplication::translate("zhuce", "<html><head/><body><p><span style=\" font-size:18pt;\">\350\272\253\344\273\275\350\257\201</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("zhuce", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\247\223\345\220\215</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class zhuce: public Ui_zhuce {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZHUCE_H
