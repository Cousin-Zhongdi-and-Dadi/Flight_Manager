/********************************************************************************
** Form generated from reading UI file 'gaiqian.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAIQIAN_H
#define UI_GAIQIAN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customer_GaiQian
{
public:
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEditChu;
    QPushButton *backwardButton;
    QLabel *label;
    QLabel *label_3;
    QPushButton *searchButton;
    QLabel *titleLabel;
    QLineEdit *lineEditDao;
    QDateEdit *dateEdit;
    QTableWidget *userOrderTable;

    void setupUi(QWidget *customer_GaiQian)
    {
        if (customer_GaiQian->objectName().isEmpty())
            customer_GaiQian->setObjectName("customer_GaiQian");
        customer_GaiQian->resize(1061, 611);
        label_2 = new QLabel(customer_GaiQian);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(199, 153, 51, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft Tai Le")});
        font.setPointSize(7);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(customer_GaiQian);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(560, 160, 51, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font1.setPointSize(7);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEditChu = new QLineEdit(customer_GaiQian);
        lineEditChu->setObjectName("lineEditChu");
        lineEditChu->setGeometry(QRect(240, 175, 91, 21));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font2.setPointSize(14);
        lineEditChu->setFont(font2);
        lineEditChu->setAutoFillBackground(false);
        lineEditChu->setStyleSheet(QString::fromUtf8("border: none"));
        backwardButton = new QPushButton(customer_GaiQian);
        backwardButton->setObjectName("backwardButton");
        backwardButton->setGeometry(QRect(0, 10, 80, 24));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        font3.setKerning(true);
        backwardButton->setFont(font3);
        backwardButton->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        backwardButton->setMouseTracking(true);
        backwardButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: none; border-radius: 3px; color: black; } \n"
"QPushButton:hover { background-color:rgb(233, 182, 163); }\n"
""));
        label = new QLabel(customer_GaiQian);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1059, 639));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/bgground2.png);"));
        label_3 = new QLabel(customer_GaiQian);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(379, 155, 41, 20));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        searchButton = new QPushButton(customer_GaiQian);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(790, 174, 71, 31));
        QFont font4;
        font4.setPointSize(12);
        searchButton->setFont(font4);
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton { background-color: rgb(233, 28, 35); border-radius: 3px; color: rgb(255, 255, 255); } \n"
"QPushButton:hover { background-color:rgb(255, 32, 36); }\n"
""));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("audio-card")));
        searchButton->setIcon(icon);
        searchButton->setCheckable(false);
        searchButton->setChecked(false);
        searchButton->setAutoDefault(false);
        titleLabel = new QLabel(customer_GaiQian);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(464, 110, 101, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("\346\226\260\345\256\213\344\275\223")});
        font5.setPointSize(13);
        titleLabel->setFont(font5);
        titleLabel->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        titleLabel->setFrameShape(QFrame::Shape::NoFrame);
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEditDao = new QLineEdit(customer_GaiQian);
        lineEditDao->setObjectName("lineEditDao");
        lineEditDao->setGeometry(QRect(412, 176, 113, 23));
        lineEditDao->setFont(font2);
        lineEditDao->setStyleSheet(QString::fromUtf8("border: none"));
        dateEdit = new QDateEdit(customer_GaiQian);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(600, 170, 151, 31));
        userOrderTable = new QTableWidget(customer_GaiQian);
        userOrderTable->setObjectName("userOrderTable");
        userOrderTable->setGeometry(QRect(20, 230, 1021, 361));
        label->raise();
        label_2->raise();
        label_4->raise();
        lineEditChu->raise();
        backwardButton->raise();
        label_3->raise();
        searchButton->raise();
        titleLabel->raise();
        lineEditDao->raise();
        dateEdit->raise();
        userOrderTable->raise();

        retranslateUi(customer_GaiQian);

        searchButton->setDefault(false);


        QMetaObject::connectSlotsByName(customer_GaiQian);
    } // setupUi

    void retranslateUi(QWidget *customer_GaiQian)
    {
        customer_GaiQian->setWindowTitle(QCoreApplication::translate("customer_GaiQian", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("customer_GaiQian", "\345\207\272\345\217\221", nullptr));
        label_4->setText(QCoreApplication::translate("customer_GaiQian", "\346\227\266\351\227\264", nullptr));
        backwardButton->setText(QCoreApplication::translate("customer_GaiQian", "<-\350\277\224\345\233\236", nullptr));
#if QT_CONFIG(whatsthis)
        label->setWhatsThis(QCoreApplication::translate("customer_GaiQian", "<html><head/><body><p><img src=\":/new/prefix1/bgground2.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("customer_GaiQian", "\345\210\260\350\276\276", nullptr));
        searchButton->setText(QCoreApplication::translate("customer_GaiQian", "\346\220\234\347\264\242", nullptr));
        titleLabel->setText(QCoreApplication::translate("customer_GaiQian", "\350\210\252\347\217\255\346\220\234\347\264\242", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("customer_GaiQian", "yyyy-MM-dd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customer_GaiQian: public Ui_customer_GaiQian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAIQIAN_H
