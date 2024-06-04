//
// Created by tanas on 5/20/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_load.h" resolved

#include "load.h"
#include "ui_load.h"
#include <qlayout.h>
#include <qlabel.h>
#include <qformlayout.h>
#include <qpushbutton.h>

load::load(QWidget *parent) :
        QWidget(parent){
    this->init();
}

load::~load() {
//    delete ui;
}

void load::init() {

    QVBoxLayout* main_layout = new QVBoxLayout(this);
    QLabel* types = new QLabel("Do you want to load existing data or do you want to start with a fresh repository?");
    QGridLayout* buttons = new QGridLayout;
    QPushButton* load_data = new QPushButton("Load");
    QPushButton* dont_load = new QPushButton("Fresh Repository");

    connect(load_data, &QPushButton::clicked, this, &load:: load_data_selected);
    connect(dont_load, &QPushButton::clicked, this, &load:: dont_load_data_selected);

    buttons->addWidget(load_data, 0,0);
    buttons->addWidget(dont_load, 0, 1);

    main_layout->addWidget(types);
    main_layout->addLayout(buttons);

}
