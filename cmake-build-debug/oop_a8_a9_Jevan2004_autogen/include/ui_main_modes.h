/********************************************************************************
** Form generated from reading UI file 'main_modes.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_MODES_H
#define UI_MAIN_MODES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_modes
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *welcome;
    QLabel *who;
    QGridLayout *gridLayout;
    QPushButton *admin;
    QPushButton *user;
    QPushButton *exit;

    void setupUi(QWidget *main_modes)
    {
        if (main_modes->objectName().isEmpty())
            main_modes->setObjectName("main_modes");
        main_modes->resize(288, 135);
        verticalLayoutWidget_2 = new QWidget(main_modes);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(50, 20, 197, 104));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        welcome = new QLabel(verticalLayoutWidget_2);
        welcome->setObjectName("welcome");

        verticalLayout->addWidget(welcome);

        who = new QLabel(verticalLayoutWidget_2);
        who->setObjectName("who");

        verticalLayout->addWidget(who);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        admin = new QPushButton(verticalLayoutWidget_2);
        admin->setObjectName("admin");

        gridLayout->addWidget(admin, 0, 0, 1, 1);

        user = new QPushButton(verticalLayoutWidget_2);
        user->setObjectName("user");

        gridLayout->addWidget(user, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        exit = new QPushButton(verticalLayoutWidget_2);
        exit->setObjectName("exit");

        verticalLayout_2->addWidget(exit);


        retranslateUi(main_modes);

        QMetaObject::connectSlotsByName(main_modes);
    } // setupUi

    void retranslateUi(QWidget *main_modes)
    {
        main_modes->setWindowTitle(QCoreApplication::translate("main_modes", "main_modes", nullptr));
        welcome->setText(QCoreApplication::translate("main_modes", "Welcome to our Pets managing app!", nullptr));
        who->setText(QCoreApplication::translate("main_modes", "                   Who are you?", nullptr));
        admin->setText(QCoreApplication::translate("main_modes", "Admin", nullptr));
        user->setText(QCoreApplication::translate("main_modes", "User", nullptr));
        exit->setText(QCoreApplication::translate("main_modes", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_modes: public Ui_main_modes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_MODES_H
