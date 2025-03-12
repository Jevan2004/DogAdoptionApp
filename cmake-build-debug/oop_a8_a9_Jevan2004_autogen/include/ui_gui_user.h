/********************************************************************************
** Form generated from reading UI file 'gui_user.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_USER_H
#define UI_GUI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui_user
{
public:
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *user_menu;
    QPushButton *all_dogs;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *filter;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *breed_label;
    QLabel *age_label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *breed_edit;
    QLineEdit *age_edit;
    QPushButton *see_adoption_list;
    QPushButton *exit;
    QLabel *label;
    QVBoxLayout *verticalLayout_5;
    QLabel *title_current_dog;
    QGridLayout *gridLayout;
    QLabel *current_name;
    QLabel *display_name;
    QLabel *current_breed;
    QLabel *display_breed;
    QLabel *current_age;
    QLabel *display_age;
    QLabel *photo_to_display;
    QGridLayout *gridLayout_2;
    QPushButton *next;
    QPushButton *stop;
    QPushButton *Adopt;
    QVBoxLayout *verticalLayout_4;
    QLabel *all_pets;
    QListWidget *adoption_list_widget;

    void setupUi(QWidget *gui_user)
    {
        if (gui_user->objectName().isEmpty())
            gui_user->setObjectName("gui_user");
        gui_user->resize(985, 538);
        horizontalLayoutWidget_4 = new QWidget(gui_user);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(20, 20, 961, 511));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        user_menu = new QLabel(horizontalLayoutWidget_4);
        user_menu->setObjectName("user_menu");

        verticalLayout->addWidget(user_menu);

        all_dogs = new QPushButton(horizontalLayoutWidget_4);
        all_dogs->setObjectName("all_dogs");

        verticalLayout->addWidget(all_dogs);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        filter = new QPushButton(horizontalLayoutWidget_4);
        filter->setObjectName("filter");

        horizontalLayout->addWidget(filter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        breed_label = new QLabel(horizontalLayoutWidget_4);
        breed_label->setObjectName("breed_label");

        verticalLayout_3->addWidget(breed_label);

        age_label = new QLabel(horizontalLayoutWidget_4);
        age_label->setObjectName("age_label");

        verticalLayout_3->addWidget(age_label);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        breed_edit = new QLineEdit(horizontalLayoutWidget_4);
        breed_edit->setObjectName("breed_edit");

        verticalLayout_2->addWidget(breed_edit);

        age_edit = new QLineEdit(horizontalLayoutWidget_4);
        age_edit->setObjectName("age_edit");

        verticalLayout_2->addWidget(age_edit);


        horizontalLayout_2->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        see_adoption_list = new QPushButton(horizontalLayoutWidget_4);
        see_adoption_list->setObjectName("see_adoption_list");

        verticalLayout->addWidget(see_adoption_list);

        exit = new QPushButton(horizontalLayoutWidget_4);
        exit->setObjectName("exit");

        verticalLayout->addWidget(exit);

        label = new QLabel(horizontalLayoutWidget_4);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(5, 3);

        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        title_current_dog = new QLabel(horizontalLayoutWidget_4);
        title_current_dog->setObjectName("title_current_dog");

        verticalLayout_5->addWidget(title_current_dog);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        current_name = new QLabel(horizontalLayoutWidget_4);
        current_name->setObjectName("current_name");

        gridLayout->addWidget(current_name, 0, 1, 1, 1);

        display_name = new QLabel(horizontalLayoutWidget_4);
        display_name->setObjectName("display_name");

        gridLayout->addWidget(display_name, 0, 0, 1, 1);

        current_breed = new QLabel(horizontalLayoutWidget_4);
        current_breed->setObjectName("current_breed");

        gridLayout->addWidget(current_breed, 1, 1, 1, 1);

        display_breed = new QLabel(horizontalLayoutWidget_4);
        display_breed->setObjectName("display_breed");

        gridLayout->addWidget(display_breed, 1, 0, 1, 1);

        current_age = new QLabel(horizontalLayoutWidget_4);
        current_age->setObjectName("current_age");

        gridLayout->addWidget(current_age, 3, 1, 1, 1);

        display_age = new QLabel(horizontalLayoutWidget_4);
        display_age->setObjectName("display_age");

        gridLayout->addWidget(display_age, 3, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        photo_to_display = new QLabel(horizontalLayoutWidget_4);
        photo_to_display->setObjectName("photo_to_display");

        verticalLayout_5->addWidget(photo_to_display);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        next = new QPushButton(horizontalLayoutWidget_4);
        next->setObjectName("next");

        gridLayout_2->addWidget(next, 0, 1, 1, 1);

        stop = new QPushButton(horizontalLayoutWidget_4);
        stop->setObjectName("stop");

        gridLayout_2->addWidget(stop, 0, 0, 1, 1);

        Adopt = new QPushButton(horizontalLayoutWidget_4);
        Adopt->setObjectName("Adopt");

        gridLayout_2->addWidget(Adopt, 0, 2, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 5);

        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        all_pets = new QLabel(horizontalLayoutWidget_4);
        all_pets->setObjectName("all_pets");

        verticalLayout_4->addWidget(all_pets);

        adoption_list_widget = new QListWidget(horizontalLayoutWidget_4);
        adoption_list_widget->setObjectName("adoption_list_widget");

        verticalLayout_4->addWidget(adoption_list_widget);


        horizontalLayout_4->addLayout(verticalLayout_4);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 1);

        retranslateUi(gui_user);

        QMetaObject::connectSlotsByName(gui_user);
    } // setupUi

    void retranslateUi(QWidget *gui_user)
    {
        gui_user->setWindowTitle(QCoreApplication::translate("gui_user", "gui_user", nullptr));
        user_menu->setText(QCoreApplication::translate("gui_user", "                              User menu", nullptr));
        all_dogs->setText(QCoreApplication::translate("gui_user", "See all dogs", nullptr));
        filter->setText(QCoreApplication::translate("gui_user", "Filter", nullptr));
        breed_label->setText(QCoreApplication::translate("gui_user", "Breed", nullptr));
        age_label->setText(QCoreApplication::translate("gui_user", "Age", nullptr));
        see_adoption_list->setText(QCoreApplication::translate("gui_user", "See adoption list", nullptr));
        exit->setText(QCoreApplication::translate("gui_user", "Exit", nullptr));
        label->setText(QString());
        title_current_dog->setText(QCoreApplication::translate("gui_user", "                                                                   Current dog", nullptr));
        current_name->setText(QCoreApplication::translate("gui_user", "-", nullptr));
        display_name->setText(QCoreApplication::translate("gui_user", "Name", nullptr));
        current_breed->setText(QCoreApplication::translate("gui_user", "-", nullptr));
        display_breed->setText(QCoreApplication::translate("gui_user", "Breed", nullptr));
        current_age->setText(QCoreApplication::translate("gui_user", "-", nullptr));
        display_age->setText(QCoreApplication::translate("gui_user", "Age", nullptr));
        photo_to_display->setText(QString());
        next->setText(QCoreApplication::translate("gui_user", "Next", nullptr));
        stop->setText(QCoreApplication::translate("gui_user", "Stop", nullptr));
        Adopt->setText(QCoreApplication::translate("gui_user", "Adopt", nullptr));
        all_pets->setText(QCoreApplication::translate("gui_user", "Adoption List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gui_user: public Ui_gui_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_USER_H
