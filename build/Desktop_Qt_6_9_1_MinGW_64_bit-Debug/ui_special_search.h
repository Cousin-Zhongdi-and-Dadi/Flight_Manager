/********************************************************************************
** Form generated from reading UI file 'special_search.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPECIAL_SEARCH_H
#define UI_SPECIAL_SEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Special_search
{
public:
    QLabel *label;
    QLabel *label_6;
    QLineEdit *lineEditChu;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QDateEdit *dateEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *timeearly;
    QPushButton *timelate;
    QPushButton *pricelow;
    QPushButton *pricehigh;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Special_search)
    {
        if (Special_search->objectName().isEmpty())
            Special_search->setObjectName("Special_search");
        Special_search->resize(1070, 611);
        label = new QLabel(Special_search);
        label->setObjectName("label");
        label->setGeometry(QRect(-90, 0, 1161, 608));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8(""));
        label_6 = new QLabel(Special_search);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(480, 110, 121, 20));
        QFont font;
        font.setPointSize(14);
        label_6->setFont(font);
        lineEditChu = new QLineEdit(Special_search);
        lineEditChu->setObjectName("lineEditChu");
        lineEditChu->setGeometry(QRect(260, 170, 261, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font1.setPointSize(14);
        lineEditChu->setFont(font1);
        lineEditChu->setStyleSheet(QString::fromUtf8("border: none"));
        pushButton = new QPushButton(Special_search);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(790, 170, 71, 31));
        QFont font2;
        font2.setPointSize(12);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(233, 28, 35); border-radius: 3px; color: rgb(255, 255, 255); } \n"
"QPushButton:hover { background-color:rgb(255, 32, 36); }\n"
""));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("audio-card")));
        pushButton->setIcon(icon);
        pushButton->setCheckable(false);
        pushButton->setChecked(false);
        pushButton->setAutoDefault(false);
        tableWidget = new QTableWidget(Special_search);
        if (tableWidget->columnCount() < 11)
            tableWidget->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 270, 1011, 271));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setMaximumSize(QSize(1100, 16777215));
        tableWidget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(242, 242, 242);"));
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(11);
        tableWidget->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget->verticalHeader()->setMinimumSectionSize(18);
        tableWidget->verticalHeader()->setDefaultSectionSize(29);
        dateEdit = new QDateEdit(Special_search);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(610, 180, 110, 22));
        dateEdit->setFont(font2);
        dateEdit->setDateTime(QDateTime(QDate(2024, 12, 9), QTime(0, 0, 0)));
        widget = new QWidget(Special_search);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(230, 220, 500, 60));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(500, 60));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        timeearly = new QPushButton(widget);
        timeearly->setObjectName("timeearly");

        horizontalLayout->addWidget(timeearly);

        timelate = new QPushButton(widget);
        timelate->setObjectName("timelate");

        horizontalLayout->addWidget(timelate);

        pricelow = new QPushButton(widget);
        pricelow->setObjectName("pricelow");

        horizontalLayout->addWidget(pricelow);

        pricehigh = new QPushButton(widget);
        pricehigh->setObjectName("pricehigh");

        horizontalLayout->addWidget(pricehigh);

        pushButton_3 = new QPushButton(Special_search);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 10, 80, 18));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton { background-color: none; border-radius: 3px; color: black; } \n"
"QPushButton:hover { background-color:rgb(233, 182, 163); }"));

        retranslateUi(Special_search);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Special_search);
    } // setupUi

    void retranslateUi(QWidget *Special_search)
    {
        Special_search->setWindowTitle(QCoreApplication::translate("Special_search", "Form", nullptr));
        label->setText(QString());
        label_6->setText(QCoreApplication::translate("Special_search", "\347\211\271\344\273\267\350\210\252\347\217\255", nullptr));
        pushButton->setText(QCoreApplication::translate("Special_search", "\346\220\234\347\264\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Special_search", "\347\233\256\347\232\204\345\234\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Special_search", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Special_search", "\350\210\252\347\251\272\345\205\254\345\217\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Special_search", "\346\234\272\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Special_search", "\350\265\267\351\243\236\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Special_search", "\350\265\267\351\243\236\346\234\272\345\234\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Special_search", "\345\210\260\350\276\276\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Special_search", "\345\210\260\350\276\276\346\234\272\345\234\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Special_search", "\345\207\206\347\202\271\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Special_search", "\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Special_search", "\346\223\215\344\275\234", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("Special_search", "yyyy/MM/dd", nullptr));
        timeearly->setText(QCoreApplication::translate("Special_search", "\350\265\267\351\243\236\346\227\266\351\227\264\344\273\216\346\227\251\345\210\260\346\231\232", nullptr));
        timelate->setText(QCoreApplication::translate("Special_search", "\350\265\267\351\243\236\346\227\266\351\227\264\344\273\216\346\231\232\345\210\260\346\227\251", nullptr));
        pricelow->setText(QCoreApplication::translate("Special_search", "\347\245\250\344\273\267\344\273\216\344\275\216\345\210\260\351\253\230", nullptr));
        pricehigh->setText(QCoreApplication::translate("Special_search", "\347\245\250\344\273\267\344\273\216\351\253\230\345\210\260\344\275\216", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Special_search", "->\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Special_search: public Ui_Special_search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPECIAL_SEARCH_H
