/********************************************************************************
** Form generated from reading UI file 'flight_search.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHT_SEARCH_H
#define UI_FLIGHT_SEARCH_H

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

class Ui_Flight_sereach
{
public:
    QLineEdit *lineEditDao;
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
    QPushButton *specialButton;
    QLabel *label_2;
    QLabel *labDateTime;
    QLabel *label_7;

    void setupUi(QWidget *Flight_sereach)
    {
        if (Flight_sereach->objectName().isEmpty())
            Flight_sereach->setObjectName("Flight_sereach");
        Flight_sereach->resize(1070, 611);
        lineEditDao = new QLineEdit(Flight_sereach);
        lineEditDao->setObjectName("lineEditDao");
        lineEditDao->setGeometry(QRect(460, 180, 113, 23));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(14);
        lineEditDao->setFont(font);
        lineEditDao->setStyleSheet(QString::fromUtf8("border: none"));
        label_6 = new QLabel(Flight_sereach);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(480, 110, 121, 20));
        QFont font1;
        font1.setPointSize(14);
        label_6->setFont(font1);
        lineEditChu = new QLineEdit(Flight_sereach);
        lineEditChu->setObjectName("lineEditChu");
        lineEditChu->setGeometry(QRect(220, 180, 91, 21));
        lineEditChu->setFont(font);
        lineEditChu->setStyleSheet(QString::fromUtf8("border: none"));
        pushButton = new QPushButton(Flight_sereach);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(900, 190, 71, 31));
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
        tableWidget = new QTableWidget(Flight_sereach);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
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
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(30, 270, 1011, 271));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMaximumSize(QSize(1100, 16777215));
        tableWidget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(242, 242, 242);"));
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(10);
        tableWidget->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget->verticalHeader()->setMinimumSectionSize(18);
        tableWidget->verticalHeader()->setDefaultSectionSize(29);
        dateEdit = new QDateEdit(Flight_sereach);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(690, 180, 121, 31));
        dateEdit->setFont(font2);
        dateEdit->setDateTime(QDateTime(QDate(2024, 12, 8), QTime(0, 0, 0)));
        widget = new QWidget(Flight_sereach);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(230, 220, 500, 60));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
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

        pushButton_3 = new QPushButton(Flight_sereach);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 10, 80, 18));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton { background-color: none; border-radius: 3px; color: black; } \n"
"QPushButton:hover { background-color:rgb(233, 182, 163); }"));
        specialButton = new QPushButton(Flight_sereach);
        specialButton->setObjectName("specialButton");
        specialButton->setGeometry(QRect(900, 150, 71, 31));
        specialButton->setFont(font2);
        specialButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(233, 28, 35); border-radius: 3px; color: rgb(255, 255, 255); } \n"
"QPushButton:hover { background-color:rgb(255, 32, 36); }\n"
""));
        specialButton->setIcon(icon);
        specialButton->setCheckable(false);
        specialButton->setChecked(false);
        specialButton->setAutoDefault(false);
        label_2 = new QLabel(Flight_sereach);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 140, 671, 81));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/img/search.png);"));
        labDateTime = new QLabel(Flight_sereach);
        labDateTime->setObjectName("labDateTime");
        labDateTime->setGeometry(QRect(340, 570, 451, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font3.setPointSize(14);
        labDateTime->setFont(font3);
        label_7 = new QLabel(Flight_sereach);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(250, 570, 121, 20));
        label_7->setFont(font1);
        label_2->raise();
        lineEditDao->raise();
        label_6->raise();
        lineEditChu->raise();
        pushButton->raise();
        tableWidget->raise();
        dateEdit->raise();
        widget->raise();
        pushButton_3->raise();
        specialButton->raise();
        labDateTime->raise();
        label_7->raise();

        retranslateUi(Flight_sereach);

        pushButton->setDefault(false);
        specialButton->setDefault(false);


        QMetaObject::connectSlotsByName(Flight_sereach);
    } // setupUi

    void retranslateUi(QWidget *Flight_sereach)
    {
        Flight_sereach->setWindowTitle(QCoreApplication::translate("Flight_sereach", "Form", nullptr));
        label_6->setText(QCoreApplication::translate("Flight_sereach", "\350\210\252\347\217\255\346\220\234\347\264\242", nullptr));
        pushButton->setText(QCoreApplication::translate("Flight_sereach", "\346\220\234\347\264\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Flight_sereach", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Flight_sereach", "\350\210\252\347\251\272\345\205\254\345\217\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Flight_sereach", "\346\234\272\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Flight_sereach", "\350\265\267\351\243\236\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Flight_sereach", "\350\265\267\351\243\236\346\234\272\345\234\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Flight_sereach", "\345\210\260\350\276\276\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Flight_sereach", "\345\210\260\350\276\276\346\234\272\345\234\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Flight_sereach", "\345\207\206\347\202\271\347\216\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Flight_sereach", "\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Flight_sereach", "\346\223\215\344\275\234", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("Flight_sereach", "yyyy/MM/dd", nullptr));
        timeearly->setText(QCoreApplication::translate("Flight_sereach", "\350\265\267\351\243\236\346\227\266\351\227\264\344\273\216\346\227\251\345\210\260\346\231\232", nullptr));
        timelate->setText(QCoreApplication::translate("Flight_sereach", "\350\265\267\351\243\236\346\227\266\351\227\264\344\273\216\346\231\232\345\210\260\346\227\251", nullptr));
        pricelow->setText(QCoreApplication::translate("Flight_sereach", "\347\245\250\344\273\267\344\273\216\344\275\216\345\210\260\351\253\230", nullptr));
        pricehigh->setText(QCoreApplication::translate("Flight_sereach", "\347\245\250\344\273\267\344\273\216\351\253\230\345\210\260\344\275\216", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Flight_sereach", "->\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
        specialButton->setText(QCoreApplication::translate("Flight_sereach", "\347\211\271\344\273\267\346\234\272\347\245\250", nullptr));
        label_2->setText(QString());
        labDateTime->setText(QString());
        label_7->setText(QCoreApplication::translate("Flight_sereach", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Flight_sereach: public Ui_Flight_sereach {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHT_SEARCH_H
