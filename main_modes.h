// main_modes.h
#ifndef OOP_A8_A9_JEVAN2004_MAIN_MODES_H
#define OOP_A8_A9_JEVAN2004_MAIN_MODES_H

#include <QWidget>
#include <QApplication>
#include <qlayout.h>
#include <qlabel.h>
#include <qformlayout.h>
#include <qpushbutton.h>
#include "gui1.h"
#include "AdoptionListService.h"
#include "service.h"
#include "gui_user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class main_modes; }
QT_END_NAMESPACE

class main_modes : public QWidget {
Q_OBJECT

public:
    main_modes(Service& serv, AdoptionListService& adoption_service, QWidget *parent = nullptr);
    ~main_modes() override;

private slots:
    void manage_admin();
    void manage_user();
    void exit_aplication();

private:
    Ui::main_modes *ui;
    Service& service;  // Reference to Service object
    AdoptionListService& adoption_service;  // Reference to AdoptionListService object
    GUI admin_gui; // Admin mode GUI
    gui_user user_gui;
};

#endif //OOP_A8_A9_JEVAN2004_MAIN_MODES_H
