//
// Created by tanas on 5/21/2024.
//

#ifndef OOP_A8_A9_JEVAN2004_GUI_USER_H
#define OOP_A8_A9_JEVAN2004_GUI_USER_H
#include "service.h"
#include "AdoptionListService.h"

#include <QWidget>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QBuffer>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class gui_user; }
QT_END_NAMESPACE

class gui_user : public QWidget {
Q_OBJECT

public:
    gui_user(Service& serv, AdoptionListService& adoption_service, QWidget *parent = nullptr);

    ~gui_user() override;

private:
    Ui::gui_user *ui;
    Service& service;  // Reference to Service object
    AdoptionListService& adoption_service;
    std::vector<Pets> pet_list;
    QNetworkAccessManager* networkManager;
    int index = 0;

    void exit_aplication();
    void see_all_pets_clicked();
    void next_clicked();
    void stop_clicked();
    void adopt_clicked();
    void filter_clicked();
    void see_adoption_list();
    void populate_list();
    void display_pet_info(const Pets& pet);
    void onImageFetched(QNetworkReply* reply);

};


#endif //OOP_A8_A9_JEVAN2004_GUI_USER_H
