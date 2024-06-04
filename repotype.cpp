//
// Created by tanas on 5/14/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RepoType.h" resolved

#include "repotype.h"
#include <qlayout.h>
#include <qlabel.h>
#include <qformlayout.h>
#include <vector>

RepoType::RepoType(QWidget *parent) : QWidget{ parent }
{
    this->init();
}

void RepoType::init() {
    QHBoxLayout* mainLayout = new QHBoxLayout{this};
    QLabel* types = new QLabel{"What kind of repo do you want?" };
    QGridLayout* buttonsLayout = new QGridLayout;
    QPushButton* CSV = new QPushButton{"CSV"};
    QPushButton* HTML = new QPushButton{"HTML"};
    QPushButton* TextFile = new QPushButton{"TEXT FILE"};
    QPushButton* Memory = new QPushButton{"Memory"};


    connect(CSV, &QPushButton::clicked, this, &RepoType::csvSelected);
    connect(HTML, &QPushButton::clicked, this, &RepoType::htmlSelected);
    connect(TextFile, &QPushButton::clicked, this, &RepoType::textFileSelected);
    connect(Memory, &QPushButton::clicked, this, &RepoType::memorySelected);

    buttonsLayout->addWidget(CSV, 0, 0);
    buttonsLayout->addWidget(HTML, 0, 1);
    buttonsLayout->addWidget(TextFile, 0, 2);
    buttonsLayout->addWidget(Memory, 1, 1);

    mainLayout->addWidget(types);
    mainLayout->addLayout(buttonsLayout);
}


