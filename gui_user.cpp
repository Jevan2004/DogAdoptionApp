//
// Created by tanas on 5/21/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui_user.h" resolved

#include <QMessageBox>
#include "gui_user.h"
#include "ui_gui_user.h"


gui_user::gui_user(Service& serv,  AdoptionListService& adopstion_service,  QWidget* parent): QWidget{ parent }, adoption_service{adopstion_service} , service{ serv }, ui(new Ui::gui_user) {
    ui->setupUi(this);

    networkManager = new QNetworkAccessManager(this);

    connect(ui->exit, &QPushButton::clicked, this, &gui_user::exit_aplication);
    connect(ui->all_dogs, &QPushButton::clicked, this, &gui_user::see_all_pets_clicked);
    connect(ui->stop, &QPushButton::clicked, this, &gui_user::stop_clicked);
    connect(ui->next, &QPushButton::clicked, this, &gui_user::next_clicked);
    connect(ui->Adopt, &QPushButton::clicked, this, &gui_user::adopt_clicked);
    connect(ui->filter, &QPushButton::clicked, this, &gui_user::filter_clicked);
    connect(ui->see_adoption_list, &QPushButton::clicked, this, &gui_user::see_adoption_list);

    connect(networkManager, &QNetworkAccessManager::finished, this, &gui_user::onImageFetched);

    this->populate_list();
}

gui_user::~gui_user() {
    delete ui;
    delete networkManager;
}

void gui_user::exit_aplication() {
    close();
}

void gui_user::see_all_pets_clicked() {
    pet_list = service.get_all_pets();
    index = 0;

    display_pet_info(pet_list[index]);
}

void gui_user::display_pet_info(const Pets& pet) {
    ui->current_name->setText(QString::fromStdString(pet.getName()));
    ui->current_breed->setText(QString::fromStdString(pet.getBreed()));
    ui->current_age->setText(QString::number(pet.getAge()));

    std::string url = pet.getPhotograph();
    std::string command = "start " + url;
    system(command.c_str());

    QUrl imageUrl(QString::fromStdString(pet.getPhotograph()));
    QNetworkRequest request(imageUrl);
    networkManager->get(request);

}

void gui_user::onImageFetched(QNetworkReply* reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray image_data = reply->readAll();
        QPixmap pixmap;
        if (pixmap.loadFromData(image_data)) {
            ui->photo_to_display->setPixmap(pixmap);
            ui->photo_to_display->setScaledContents(true);
        } else {
            ui->photo_to_display->setText("Unable to load image data");
        }
    } else {
        qDebug() << "Error fetching image:" << reply->errorString();
        ui->photo_to_display->setText("Image not available: " + reply->errorString());
    }
    reply->deleteLater();
}


void gui_user::next_clicked() {
    if (pet_list.empty()) {
        QMessageBox::critical(this, "Error", "No pets in the list");
        return;
    }

    index += 1;
    if(index == pet_list.size())
        index = 0;
    display_pet_info(pet_list[index]);

}

void gui_user::stop_clicked() {
    index = 0;

    ui->current_name->clear();
    ui->current_breed->clear();
    ui->current_age->clear();
    ui->photo_to_display->clear();

}

void gui_user::adopt_clicked() {
    if (pet_list.empty()) {
        QMessageBox::critical(this, "Error", "No pets in the list");
        return;
    }
    adoption_service.add_to_adoption_list(pet_list[index]);
    int index1 = service.get_position_of_pet(pet_list[index]);
    service.remove_pet_service(index1);

    this->populate_list();
    this->next_clicked();
}

void gui_user::filter_clicked() {
    QString breed = ui->breed_edit->text();
    QString age = ui->age_edit->text();

    if (age.isEmpty()) {
        QMessageBox::critical(this, "Error", "Please fill in all fields.");
        return;
    }

    bool conversionOk = false;
    int age1 = age.toInt(&conversionOk);
    if (!conversionOk || age1 < 0) {
        QMessageBox::critical(this, "Error", "Please enter a valid age (non-negative integer).");
        return;
    }

    try {
        pet_list = service.get_pets_by_breed_and_age(breed.toStdString(), age1);
    }
    catch (const std::exception& e){
        QMessageBox::critical(this, "Error", e.what());
    }

    index = 0;
    next_clicked();
}

void gui_user::see_adoption_list() {
    if(this->service.get_repo_type() == "memory") {
        QMessageBox::critical(this, "Message", "Please look at the right part of the window");

    }
    else if(this->service.get_repo_type() == "html")
    {
        std::string command = "start chrome.exe D:\\HomeworksOOP\\oop-a8-9-Jevan2004\\cmake-build-debug\\" + this->adoption_service.get_file_name();
        system(command.c_str());
    }
    else
    {
        std::string command = "start /B notepad.exe " + this->adoption_service.get_file_name();
        system(command.c_str());
    }
}

void gui_user::populate_list() {
    this->ui->adoption_list_widget->clear();;

    std::vector<Pets> pets = this->adoption_service.get_adoption_list();    

    for(Pets pet : pets)
    {
        this->ui->adoption_list_widget->addItem(QString::fromStdString(pet.getName() + " - " + pet.getBreed() + " - " + std::to_string(pet.getAge())));
    }
}
