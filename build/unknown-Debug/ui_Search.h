/********************************************************************************
** Form generated from reading UI file 'Search.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTableView *tableView;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QLabel *label_14;
    QDateEdit *dateEdit;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1061, 611);
        tableView = new QTableView(Form);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(320, 150, 521, 441));
        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(15, 56, 111, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font.setPointSize(15);
        pushButton_3->setFont(font);
        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(288, 56, 111, 61));
        pushButton_4->setFont(font);
        pushButton_5 = new QPushButton(Form);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(151, 56, 101, 61));
        pushButton_5->setFont(font);
        pushButton_6 = new QPushButton(Form);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(424, 56, 111, 61));
        pushButton_6->setFont(font);
        layoutWidget = new QWidget(Form);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 160, 211, 361));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName("label_14");

        gridLayout->addWidget(label_14, 2, 0, 1, 1);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName("dateEdit");

        gridLayout->addWidget(dateEdit, 2, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Form", "\346\267\273\345\212\240\350\210\252\347\217\255", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Form", "\346\237\245\350\257\242\350\210\252\347\217\255", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Form", "\346\237\245\350\257\242\350\256\242\345\215\225", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Form", "\351\200\200\345\207\272", nullptr));
        label_7->setText(QCoreApplication::translate("Form", "Flight No:", nullptr));
        lineEdit->setText(QString());
        label_8->setText(QCoreApplication::translate("Form", "ID:", nullptr));
        lineEdit_2->setText(QString());
        label_14->setText(QCoreApplication::translate("Form", "Depart Date:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
