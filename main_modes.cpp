// main_modes.cpp
#include "main_modes.h"
#include "ui_main_modes.h"

main_modes::main_modes(Service& serv,  AdoptionListService& adopstion_service,  QWidget* parent)
        : QWidget{ parent }, adoption_service{adopstion_service} , service{ serv }, ui(new Ui::main_modes),
          admin_gui{service, adoption_service}, user_gui{service, adoption_service} // Initialize the admin GUI
{
    ui->setupUi(this);

    connect(ui->admin, &QPushButton::clicked, this, &main_modes::manage_admin);
    connect(ui->user, &QPushButton::clicked, this, &main_modes::manage_user);
    connect(ui->exit, &QPushButton::clicked, this, &main_modes::exit_aplication);

}

main_modes::~main_modes() {
    delete ui;
}

void main_modes::manage_admin() {
    admin_gui.show(); // Show the admin GUI
}

void main_modes::manage_user() {
    // Handle user mode
    user_gui.show();
}

void main_modes::exit_aplication() {
    close();
}
