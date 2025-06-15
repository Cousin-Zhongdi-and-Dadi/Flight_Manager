/********************************************************************************
** Form generated from reading UI file 'customor_dingpao.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMOR_DINGPAO_H
#define UI_CUSTOMOR_DINGPAO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Customor_DingPao
{
public:
    QLabel *label_8;
    QLabel *label_15;
    QLabel *label_12;
    QPushButton *pushButton;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_9;
    QLineEdit *lineEditLauTime;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_2;
    QLabel *label_10;
    QLineEdit *lineEditPrice3;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_5;
    QLabel *label_11;
    QLineEdit *lineEditPrice2;
    QLabel *label_6;
    QLineEdit *lineEditCode;
    QLabel *label_18;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_20;
    QGraphicsView *graphicsView;
    QLineEdit *lineEditArrTime;
    QLineEdit *lineEditDate;
    QLineEdit *lineEditLauCity;
    QLineEdit *lineEditPrice1;
    QLineEdit *lineEditName;
    QLineEdit *lineEditSfz;
    QLineEdit *lineEditArrCity;
    QPushButton *pushButtonBack;
    QLabel *label_3;
    QComboBox *seat;
    QLabel *label_21;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_19;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLineEdit *lineEditLauPort;
    QLineEdit *lineEditArrPort;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *lineEditAccount;

    void setupUi(QWidget *Customor_DingPao)
    {
        if (Customor_DingPao->objectName().isEmpty())
            Customor_DingPao->setObjectName("Customor_DingPao");
        Customor_DingPao->resize(1060, 611);
        label_8 = new QLabel(Customor_DingPao);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(460, 220, 221, 51));
        label_8->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.10.png);"));
        label_15 = new QLabel(Customor_DingPao);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(370, 160, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font.setPointSize(15);
        font.setBold(true);
        label_15->setFont(font);
        label_15->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_12 = new QLabel(Customor_DingPao);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(110, 150, 211, 51));
        label_12->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.10.png);"));
        pushButton = new QPushButton(Customor_DingPao);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(800, 430, 111, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font1.setPointSize(15);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"background-color: rgb(233, 28, 35); \n"
"border-radius: 8px;\n"
" color: rgb(255, 255, 255);\n"
" } \n"
"QPushButton:hover { background-color:rgb(255, 32, 36); }\n"
""));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("audio-card")));
        pushButton->setIcon(icon);
        pushButton->setCheckable(false);
        pushButton->setChecked(false);
        pushButton->setAutoDefault(false);
        label_7 = new QLabel(Customor_DingPao);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 230, 71, 31));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label = new QLabel(Customor_DingPao);
        label->setObjectName("label");
        label->setGeometry(QRect(113, 350, 561, 121));
        label->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(Customor_DingPao);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 440, 41, 31));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_9 = new QLabel(Customor_DingPao);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(390, 230, 71, 31));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        lineEditLauTime = new QLineEdit(Customor_DingPao);
        lineEditLauTime->setObjectName("lineEditLauTime");
        lineEditLauTime->setEnabled(false);
        lineEditLauTime->setGeometry(QRect(150, 160, 161, 23));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font2.setPointSize(14);
        lineEditLauTime->setFont(font2);
        lineEditLauTime->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditLauTime->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_13 = new QLabel(Customor_DingPao);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(460, 150, 221, 51));
        label_13->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.10.png);"));
        label_14 = new QLabel(Customor_DingPao);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 160, 91, 31));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_2 = new QLabel(Customor_DingPao);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(103, 380, 581, 131));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.8.png);"));
        label_2->setScaledContents(true);
        label_10 = new QLabel(Customor_DingPao);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(110, 80, 211, 51));
        label_10->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.10.png);"));
        lineEditPrice3 = new QLineEdit(Customor_DingPao);
        lineEditPrice3->setObjectName("lineEditPrice3");
        lineEditPrice3->setEnabled(false);
        lineEditPrice3->setGeometry(QRect(550, 440, 71, 23));
        lineEditPrice3->setFont(font2);
        lineEditPrice3->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditPrice3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_16 = new QLabel(Customor_DingPao);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(460, 80, 221, 51));
        label_16->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.9.png);"));
        label_17 = new QLabel(Customor_DingPao);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(360, 90, 91, 31));
        label_17->setFont(font);
        label_17->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_5 = new QLabel(Customor_DingPao);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(710, 340, 61, 31));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_11 = new QLabel(Customor_DingPao);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 90, 91, 31));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        lineEditPrice2 = new QLineEdit(Customor_DingPao);
        lineEditPrice2->setObjectName("lineEditPrice2");
        lineEditPrice2->setEnabled(false);
        lineEditPrice2->setGeometry(QRect(350, 440, 81, 23));
        lineEditPrice2->setFont(font2);
        lineEditPrice2->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditPrice2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_6 = new QLabel(Customor_DingPao);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(110, 210, 211, 81));
        label_6->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.9.png);"));
        lineEditCode = new QLineEdit(Customor_DingPao);
        lineEditCode->setObjectName("lineEditCode");
        lineEditCode->setEnabled(false);
        lineEditCode->setGeometry(QRect(500, 90, 161, 23));
        lineEditCode->setFont(font2);
        lineEditCode->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditCode->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_18 = new QLabel(Customor_DingPao);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(680, 290, 91, 31));
        label_18->setFont(font);
        label_18->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_22 = new QLabel(Customor_DingPao);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(780, 280, 221, 51));
        label_22->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.10.png);"));
        label_23 = new QLabel(Customor_DingPao);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(780, 230, 221, 51));
        label_23->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.10.png);"));
        label_20 = new QLabel(Customor_DingPao);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(640, 230, 131, 41));
        label_20->setFont(font);
        label_20->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        graphicsView = new QGraphicsView(Customor_DingPao);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 1062, 621));
        graphicsView->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.16.jpg);"));
        lineEditArrTime = new QLineEdit(Customor_DingPao);
        lineEditArrTime->setObjectName("lineEditArrTime");
        lineEditArrTime->setEnabled(false);
        lineEditArrTime->setGeometry(QRect(500, 160, 161, 23));
        lineEditArrTime->setFont(font2);
        lineEditArrTime->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditArrTime->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditDate = new QLineEdit(Customor_DingPao);
        lineEditDate->setObjectName("lineEditDate");
        lineEditDate->setEnabled(false);
        lineEditDate->setGeometry(QRect(150, 90, 161, 23));
        lineEditDate->setFont(font2);
        lineEditDate->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditDate->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditLauCity = new QLineEdit(Customor_DingPao);
        lineEditLauCity->setObjectName("lineEditLauCity");
        lineEditLauCity->setEnabled(false);
        lineEditLauCity->setGeometry(QRect(150, 212, 161, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font3.setPointSize(20);
        lineEditLauCity->setFont(font3);
        lineEditLauCity->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditLauCity->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditPrice1 = new QLineEdit(Customor_DingPao);
        lineEditPrice1->setObjectName("lineEditPrice1");
        lineEditPrice1->setEnabled(false);
        lineEditPrice1->setGeometry(QRect(160, 440, 71, 23));
        lineEditPrice1->setFont(font2);
        lineEditPrice1->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditPrice1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEditName = new QLineEdit(Customor_DingPao);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setGeometry(QRect(820, 240, 161, 23));
        lineEditName->setFont(font2);
        lineEditName->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditName->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditSfz = new QLineEdit(Customor_DingPao);
        lineEditSfz->setObjectName("lineEditSfz");
        lineEditSfz->setGeometry(QRect(820, 290, 211, 23));
        lineEditSfz->setFont(font2);
        lineEditSfz->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditSfz->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditArrCity = new QLineEdit(Customor_DingPao);
        lineEditArrCity->setObjectName("lineEditArrCity");
        lineEditArrCity->setEnabled(false);
        lineEditArrCity->setGeometry(QRect(500, 212, 161, 41));
        lineEditArrCity->setFont(font3);
        lineEditArrCity->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditArrCity->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        pushButtonBack = new QPushButton(Customor_DingPao);
        pushButtonBack->setObjectName("pushButtonBack");
        pushButtonBack->setGeometry(QRect(0, 0, 101, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft YaHei UI")});
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setStrikeOut(false);
        font4.setKerning(true);
        pushButtonBack->setFont(font4);
        pushButtonBack->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonBack->setMouseTracking(true);
        pushButtonBack->setStyleSheet(QString::fromUtf8("QPushButton { background-color: none; border-radius: 3px; color: black; } \n"
"QPushButton:hover { background-color:rgb(233, 182, 163); }\n"
""));
        label_3 = new QLabel(Customor_DingPao);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 180, 231, 131));
        label_3->setStyleSheet(QString::fromUtf8(""));
        seat = new QComboBox(Customor_DingPao);
        seat->addItem(QString());
        seat->addItem(QString());
        seat->addItem(QString());
        seat->setObjectName("seat");
        seat->setGeometry(QRect(790, 340, 141, 24));
        QFont font5;
        font5.setPointSize(12);
        seat->setFont(font5);
        seat->setStyleSheet(QString::fromUtf8("background-color: rgb(253, 253, 253);"));
        label_21 = new QLabel(Customor_DingPao);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(170, 350, 71, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("\345\271\274\345\234\206")});
        font6.setPointSize(16);
        label_21->setFont(font6);
        label_24 = new QLabel(Customor_DingPao);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(370, 350, 61, 41));
        label_24->setFont(font6);
        label_25 = new QLabel(Customor_DingPao);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(560, 350, 71, 41));
        label_25->setFont(font6);
        label_19 = new QLabel(Customor_DingPao);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(0, 290, 111, 41));
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_26 = new QLabel(Customor_DingPao);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(110, 280, 211, 81));
        label_26->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.9.png);"));
        label_27 = new QLabel(Customor_DingPao);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(360, 290, 101, 41));
        label_27->setFont(font);
        label_27->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_28 = new QLabel(Customor_DingPao);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(460, 280, 211, 81));
        label_28->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.9.png);"));
        lineEditLauPort = new QLineEdit(Customor_DingPao);
        lineEditLauPort->setObjectName("lineEditLauPort");
        lineEditLauPort->setEnabled(false);
        lineEditLauPort->setGeometry(QRect(150, 300, 201, 23));
        lineEditLauPort->setFont(font2);
        lineEditLauPort->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditLauPort->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        lineEditArrPort = new QLineEdit(Customor_DingPao);
        lineEditArrPort->setObjectName("lineEditArrPort");
        lineEditArrPort->setEnabled(false);
        lineEditArrPort->setGeometry(QRect(500, 300, 201, 23));
        lineEditArrPort->setFont(font2);
        lineEditArrPort->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditArrPort->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        label_29 = new QLabel(Customor_DingPao);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(680, 190, 91, 31));
        label_29->setFont(font);
        label_29->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_30 = new QLabel(Customor_DingPao);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(780, 180, 221, 51));
        label_30->setStyleSheet(QString::fromUtf8("image: url(:/img/icon.10.png);"));
        lineEditAccount = new QLineEdit(Customor_DingPao);
        lineEditAccount->setObjectName("lineEditAccount");
        lineEditAccount->setEnabled(false);
        lineEditAccount->setGeometry(QRect(820, 190, 161, 23));
        lineEditAccount->setFont(font2);
        lineEditAccount->setStyleSheet(QString::fromUtf8("border:none"));
        lineEditAccount->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        graphicsView->raise();
        label_3->raise();
        label_8->raise();
        label_15->raise();
        label_12->raise();
        pushButton->raise();
        label_7->raise();
        label->raise();
        label_4->raise();
        label_9->raise();
        lineEditLauTime->raise();
        label_13->raise();
        label_14->raise();
        label_2->raise();
        label_10->raise();
        lineEditPrice3->raise();
        label_16->raise();
        label_17->raise();
        label_5->raise();
        label_11->raise();
        lineEditPrice2->raise();
        label_6->raise();
        lineEditCode->raise();
        label_18->raise();
        label_22->raise();
        label_23->raise();
        label_20->raise();
        lineEditArrTime->raise();
        lineEditDate->raise();
        lineEditLauCity->raise();
        lineEditPrice1->raise();
        lineEditName->raise();
        lineEditSfz->raise();
        lineEditArrCity->raise();
        pushButtonBack->raise();
        seat->raise();
        label_21->raise();
        label_24->raise();
        label_25->raise();
        label_19->raise();
        label_26->raise();
        label_27->raise();
        label_28->raise();
        lineEditLauPort->raise();
        lineEditArrPort->raise();
        label_29->raise();
        label_30->raise();
        lineEditAccount->raise();

        retranslateUi(Customor_DingPao);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(Customor_DingPao);
    } // setupUi

    void retranslateUi(QWidget *Customor_DingPao)
    {
        Customor_DingPao->setWindowTitle(QCoreApplication::translate("Customor_DingPao", "Form", nullptr));
        label_8->setText(QString());
        label_15->setText(QCoreApplication::translate("Customor_DingPao", "\345\210\260\350\276\276\346\227\266\351\227\264", nullptr));
        label_12->setText(QString());
        pushButton->setText(QCoreApplication::translate("Customor_DingPao", "\350\256\242\347\245\250", nullptr));
        label_7->setText(QCoreApplication::translate("Customor_DingPao", "\345\207\272\345\217\221\345\234\260", nullptr));
#if QT_CONFIG(whatsthis)
        label->setWhatsThis(QCoreApplication::translate("Customor_DingPao", "<html><head/><body><p><img src=\":/img/icon.8.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QString());
        label_4->setText(QCoreApplication::translate("Customor_DingPao", "\344\273\267\346\240\274", nullptr));
        label_9->setText(QCoreApplication::translate("Customor_DingPao", "\345\210\260\350\276\276\345\234\260", nullptr));
        label_13->setText(QString());
        label_14->setText(QCoreApplication::translate("Customor_DingPao", "\345\207\272\345\217\221\346\227\266\351\227\264", nullptr));
#if QT_CONFIG(whatsthis)
        label_2->setWhatsThis(QCoreApplication::translate("Customor_DingPao", "<html><head/><body><p><img src=\":/img/icon.8.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_2->setText(QString());
        label_10->setText(QString());
        label_16->setText(QString());
        label_17->setText(QCoreApplication::translate("Customor_DingPao", "\350\210\252\347\217\255\345\217\267", nullptr));
        label_5->setText(QCoreApplication::translate("Customor_DingPao", "\350\210\261\344\275\215", nullptr));
        label_11->setText(QCoreApplication::translate("Customor_DingPao", "\346\227\245\346\234\237", nullptr));
        label_6->setText(QString());
        label_18->setText(QCoreApplication::translate("Customor_DingPao", "\350\272\253\344\273\275\350\257\201", nullptr));
        label_22->setText(QString());
        label_23->setText(QString());
        label_20->setText(QCoreApplication::translate("Customor_DingPao", "\344\271\230\346\234\272\344\272\272\345\247\223\345\220\215", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("Customor_DingPao", "<-\350\277\224\345\233\236", nullptr));
        label_3->setText(QString());
        seat->setItemText(0, QCoreApplication::translate("Customor_DingPao", "\347\273\217\346\265\216\350\210\261", nullptr));
        seat->setItemText(1, QCoreApplication::translate("Customor_DingPao", "\345\225\206\345\212\241\350\210\261", nullptr));
        seat->setItemText(2, QCoreApplication::translate("Customor_DingPao", "\345\244\264\347\255\211\350\210\261", nullptr));

        label_21->setText(QCoreApplication::translate("Customor_DingPao", "\347\273\217\346\265\216\350\210\261", nullptr));
        label_24->setText(QCoreApplication::translate("Customor_DingPao", "\345\225\206\345\212\241\350\210\261", nullptr));
        label_25->setText(QCoreApplication::translate("Customor_DingPao", "\345\244\264\347\255\211\350\210\261", nullptr));
        label_19->setText(QCoreApplication::translate("Customor_DingPao", "\345\207\272\345\217\221\346\234\272\345\234\272", nullptr));
        label_26->setText(QString());
        label_27->setText(QCoreApplication::translate("Customor_DingPao", "\345\210\260\350\276\276\346\234\272\345\234\272", nullptr));
        label_28->setText(QString());
        label_29->setText(QCoreApplication::translate("Customor_DingPao", "\350\264\246\345\217\267", nullptr));
        label_30->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Customor_DingPao: public Ui_Customor_DingPao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMOR_DINGPAO_H
