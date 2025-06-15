/********************************************************************************
** Form generated from reading UI file 'databasemanager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEMANAGER_H
#define UI_DATABASEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseManager
{
public:

    void setupUi(QWidget *DatabaseManager)
    {
        if (DatabaseManager->objectName().isEmpty())
            DatabaseManager->setObjectName("DatabaseManager");
        DatabaseManager->resize(400, 300);

        retranslateUi(DatabaseManager);

        QMetaObject::connectSlotsByName(DatabaseManager);
    } // setupUi

    void retranslateUi(QWidget *DatabaseManager)
    {
        DatabaseManager->setWindowTitle(QCoreApplication::translate("DatabaseManager", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseManager: public Ui_DatabaseManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEMANAGER_H
