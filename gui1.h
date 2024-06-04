//
// Created by tanas on 5/14/2024.
//

#pragma once
#include <QWidget>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include "service.h"
#include "AdoptionListService.h"
#include <QLayout>
#include <QLabel>
#include <QFormLayout>
#include <QMessageBox>
#include <QPieSeries>
#include <QChartView>
#include <QChart>
#include <QWidget>
#include <QVBoxLayout>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QMap>
#include <QString>
#include <QBrush>
#include <QColor>
#include "ModelView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget
{
    Service& service;
    AdoptionListService& adoption_service;
    QListWidget* allPetsList;
    QLineEdit* NameEdit;
    QLineEdit* breedEdit;
    QLineEdit* ageEdit;
    QLineEdit* photoEdit;
    QPushButton* addButton;
    QPushButton* updateButton;
    QPushButton* deleteButton;
    QPushButton* exitButton;
    QPushButton* view_all_Button;
    QPushButton* chart;
    QPushButton* undo;
    QPushButton* redo;
    QPushButton* viewAdoptionListButton;
    QListWidget* allAdoptedPets;
    AdoptionListModel* adoptionListModel;

public:
    GUI(Service& serv, AdoptionListService& adopstion_service , QWidget* parent = nullptr);

    void initGUI();
    void populateList();

    void add_pet();
    void delete_pet();
    void update_pet();
    void view_file();
    void execute_undo();
    void execute_redo();
    void viewAdoptionList();


private:
    void exit_aplication();
    void see_chart();
};

//OOP_A8_A9_JEVAN2004_GUI_H
