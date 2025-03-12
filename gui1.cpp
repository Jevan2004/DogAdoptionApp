//
// Created by tanas on 5/14/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui1.h"
#include <qlayout.h>
#include <qlabel.h>
#include <qformlayout.h>
#include <vector>
#include <QMessageBox>
#include <QPieSeries>
#include <QRandomGenerator>
#include <QTableView>
#include "pets_domain.h"
#include "RepositoryException.h"
#include "pets_domain.h"
#include <QTableView>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QDialog>
#include <QShortcut>

GUI::GUI(Service& serv,  AdoptionListService& adopstion_service,  QWidget* parent): QWidget{ parent }, adoption_service{adopstion_service} , service{ serv }
{
    this->initGUI();
    this->populateList();

    connect(addButton, &QPushButton::clicked, this, &GUI::add_pet);
    connect(deleteButton, &QPushButton::clicked, this, &GUI::delete_pet);
    connect(updateButton, &QPushButton::clicked, this, &GUI::update_pet);
    connect(exitButton, &QPushButton::clicked, this, &GUI::exit_aplication);
    connect(view_all_Button,&QPushButton::clicked, this, &GUI::view_file);
    connect(chart, &QPushButton::clicked, this, &GUI::see_chart);
    connect(undo, &QPushButton::clicked, this, &GUI::execute_undo);
    connect(redo, &QPushButton::clicked, this, &GUI::execute_redo);
    connect(viewAdoptionListButton, &QPushButton::clicked, this, &GUI::viewAdoptionList);

    connect(undo_shortcut, &QShortcut::activated,this, &GUI::execute_undo);
    connect(redo_shortcut, &QShortcut::activated,this, &GUI::execute_redo);


}

void GUI::initGUI() {
    QHBoxLayout* mainLayout = new QHBoxLayout{this};

    QVBoxLayout* adminLayout = new QVBoxLayout{};
    QLabel* allPetsLabel = new QLabel{"All Pets" };
    adminLayout->addWidget(allPetsLabel);
    allPetsList = new QListWidget{};
    adminLayout->addWidget(allPetsList);

    QFormLayout* PetDataLayout = new QFormLayout;
    QLabel* PetName = new QLabel{"Name: "};
    NameEdit = new QLineEdit;
    PetDataLayout->addRow(PetName, NameEdit);

    QLabel* pet_breed = new QLabel{"Breed: " };
    breedEdit = new QLineEdit;
    PetDataLayout->addRow(pet_breed, breedEdit);

    QLabel* pet_age = new QLabel("Age: ");
    ageEdit = new QLineEdit;
    PetDataLayout->addRow(pet_age, ageEdit);

    QLabel* pet_photo = new QLabel("Photograph link: ");
    photoEdit = new QLineEdit;
    PetDataLayout->addRow(pet_photo, photoEdit);

    adminLayout->addLayout(PetDataLayout);

    QGridLayout* buttonsLayout = new QGridLayout;
    addButton = new QPushButton{"Add"};
    deleteButton = new QPushButton{"Delete"};
    updateButton = new QPushButton{"Update"};
    exitButton = new QPushButton{"Exit"};
    view_all_Button = new QPushButton{"View file"};
    chart = new QPushButton{"Chart"};
    undo = new QPushButton{"Undo"};
    redo = new QPushButton{"Redo"};
    viewAdoptionListButton = new QPushButton{"View Adoption List"};

    buttonsLayout->addWidget(addButton, 0, 0);
    buttonsLayout->addWidget(deleteButton, 0, 1);
    buttonsLayout->addWidget(updateButton, 0, 2);
    buttonsLayout->addWidget(exitButton, 1, 1);
    buttonsLayout->addWidget(view_all_Button, 1, 2);
    buttonsLayout->addWidget(chart,1,0);
    buttonsLayout->addWidget(undo,2,0);
    buttonsLayout->addWidget(redo,2,2);
    buttonsLayout->addWidget(viewAdoptionListButton, 3, 0);

    undo_shortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Z), this);
    redo_shortcut = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Y), this);


    adminLayout->addLayout(buttonsLayout);

    QVBoxLayout* middle = new QVBoxLayout{};
    QPushButton* middle_button =  new QPushButton{">"};
    QGridLayout* buttonLayoutMiddle = new QGridLayout;
    buttonLayoutMiddle->addWidget(middle_button);
    middle->addLayout(buttonLayoutMiddle);


    QVBoxLayout* adopted_pets = new QVBoxLayout{};
    QLabel* allAdoptedPetsLabel = new QLabel{"All adopted pets" };
    adopted_pets->addWidget(allAdoptedPetsLabel);
    allAdoptedPets = new QListWidget{};
    adopted_pets->addWidget(allAdoptedPets);

//    QGridLayout* adopted_buttonsLayout = new QGridLayout;
//    adoptButton = new QPushButton{"Adopt"};
//    nextButton = new QPushButton{"Next"};
//    adopted_buttonsLayout->addWidget(adoptButton, 0, 0);
//    adopted_buttonsLayout->addWidget(nextButton, 0, 1);
//
//    adopted_pets->addLayout(adopted_buttonsLayout);

    mainLayout->addLayout(adminLayout);
    mainLayout->addLayout(middle);
    mainLayout->addLayout(adopted_pets);
}

void GUI::populateList() {
    this->allPetsList->clear();

    std::vector<Pets> pets = this->service.get_all_pets();

    for(Pets pet : pets)
    {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(pet.getName() + " - " + pet.getBreed() + " - " + std::to_string(pet.getAge())));

        this->allPetsList->addItem(item);
    }

    this->allAdoptedPets->clear();
    std::vector<Pets> adopted_pets = this->adoption_service.get_adoption_list();
    for(Pets pet : adopted_pets)
    {
        this->allAdoptedPets->addItem(QString::fromStdString(pet.getName() + " - " + pet.getBreed() + " - " + std::to_string(pet.getAge())));
    }
    allPetsList->clearSelection();

}

void GUI::add_pet() {

    try {
        QString name = NameEdit->text();
        QString breed = breedEdit->text();
        QString age = ageEdit->text();
        QString photo = photoEdit->text();

        if (name.isEmpty() || breed.isEmpty() || age.isEmpty() || photo.isEmpty()) {
            QMessageBox::critical(this, "Error", "Please fill in all fields.");
            return;
        }

        bool conversionOk = false;
        int age1 = age.toInt(&conversionOk);
        if (!conversionOk || age1 < 0) {
            QMessageBox::critical(this, "Error", "Please enter a valid age (non-negative integer).");
            return;
        }

        service.add_pet_service(name.toStdString(), breed.toStdString(), age1, photo.toStdString());

        NameEdit->clear();
        breedEdit->clear();
        ageEdit->clear();
        photoEdit->clear();

        populateList();
    }
    catch (DuplicatePetException& e){
        QMessageBox::critical(this, "Error", e.what());
    }

}

void GUI::delete_pet() {
    try {
        QString name = NameEdit->text();
        QString breed = breedEdit->text();
        QString age = ageEdit->text();
        QString photo = photoEdit->text();

        if (name.isEmpty() || breed.isEmpty() || age.isEmpty() || photo.isEmpty()) {
            QMessageBox::critical(this, "Error", "Please fill in all fields.");
            return;
        }

        bool conversionOk = false;
        int age1 = age.toInt(&conversionOk);
        if (!conversionOk || age1 < 0) {
            QMessageBox::critical(this, "Error", "Please enter a valid age (non-negative integer).");
            return;
        }

        Pets to_be_removed(name.toStdString(), breed.toStdString(), 0, "");

        int position = service.get_position_of_pet(to_be_removed);

        if (position == -1) {
            throw PetNotFoundException(name.toStdString());
        }
        int result = service.remove_pet_service(position);

        if (result == -1) {
            throw PetNotFoundException(name.toStdString());
        }

        NameEdit->clear();
        breedEdit->clear();
        ageEdit->clear();
        photoEdit->clear();
        populateList();
    }
    catch (PetNotFoundException&e){
        QMessageBox::critical(this, "Error", e.what());
    }
}

void GUI::update_pet() {
    try {
        QListWidgetItem* selectedItem = allPetsList->currentItem();
        if (!selectedItem) {
            QMessageBox::critical(this, "Error", "Item is not selected!");
            return;
        }

        QString pet_info = selectedItem->text();
        QStringList pet_parts = pet_info.split(" - ");
        if(pet_parts.size() != 3) {
            QMessageBox::critical(this, "Error", "Something went wrong!");
            return;
        }

        QString name = pet_parts[0];
        QString breed = pet_parts[1];
        int age = pet_parts[2].toInt();

        QString new_name = NameEdit->text();
        QString new_breed = breedEdit->text();
        QString newAge = ageEdit->text();
        QString newPhoto = photoEdit->text();

        if (new_name.isEmpty() || new_breed.isEmpty() || newAge.isEmpty() || newPhoto.isEmpty()) {
            QMessageBox::critical(this, "Error", "Please fill in all fields.");
            return;
        }

        bool conversionOk = false;
        int age1 = newAge.toInt(&conversionOk);
        if (!conversionOk || age1 < 0) {
            QMessageBox::critical(this, "Error", "Please enter a valid age (non-negative integer).");
            return;
        }

        Pets to_be_updated(name.toStdString(), breed.toStdString(), age, "");

        int position = service.get_position_of_pet(to_be_updated);

        if(position == -1) {
            QMessageBox::critical(this, "Error", "The given pet does not exist");
            return;
        }

        Pets updated_pet(new_name.toStdString(), new_breed.toStdString(), age1, newPhoto.toStdString());

        this->service.update_pet_service(position, updated_pet);
        NameEdit->clear();
        breedEdit->clear();
        ageEdit->clear();
        photoEdit->clear();
        populateList();



    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("An error occurred: ") + e.what());
    }
}

void GUI::exit_aplication() {
    close();
}

void GUI::view_file() {
    if(this->service.get_repo_type() == "memory") {
        QMessageBox::critical(this, "Message", "Please look at the right part of the window");

    }
    else if(this->service.get_repo_type() == "html")
    {
        std::string command = "start chrome.exe D:\\HomeworksOOP\\oop-a8-9-Jevan2004\\cmake-build-debug\\" + this->service.get_repo_filename();
        system(command.c_str());
    }
    else
    {
        std::string command = "start /B notepad.exe " + this->service.get_repo_filename();
        system(command.c_str());
    }
}

void GUI::see_chart() {
    std::map<std::string, int> breeds;
    for (auto s : this->service.get_all_pets()) {
        if (breeds.find(s.getBreed()) == breeds.end())
            breeds[s.getBreed()] = 1;
        else
            breeds[s.getBreed()]++;
    }

    // Calculate dimensions for the chart
    int barWidth = 22; // Width of each bar
    int spaceBetweenBars = 100; // Space between bars (adjusted for readability)
    int numRows = breeds.size(); // Number of bars
    int maxCount = 0; // Maximum count to determine the scaling of the chart

    QFontMetrics fm(QFont("Verdana", 8)); // Font metrics for calculating text width
    for (const auto& genre : breeds) {
        maxCount = std::max(maxCount, genre.second);
    }

    int maxLabelWidth = 0; // Maximum width of breed labels

    for (const auto& genre : breeds) {
        int labelWidth = fm.horizontalAdvance(QString::fromStdString(genre.first));
        maxLabelWidth = std::max(maxLabelWidth, labelWidth);
    }

    int maxDigitWidth = fm.horizontalAdvance('9'); // Width of the widest digit
    int chartWidth = (barWidth + spaceBetweenBars) * numRows + maxLabelWidth + maxDigitWidth + 50; // Width of the chart (adjusted for labels and numbers)
    int chartHeight = maxCount * 44 + 50; // Height of the chart (scaled based on max count) + space for labels

    // Create a widget to hold the chart
    QWidget* window = new QWidget{};
    QHBoxLayout* mainLayout = new QHBoxLayout{ window };

    // Create a pixmap to draw the chart
    QPixmap pixmap(chartWidth, chartHeight);
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set up font for genre labels
    QFont font("Verdana", 8);
    painter.setFont(font);

    // Draw genre labels
    int labelHeight = fm.height(); // Height of the label text
    int x = maxLabelWidth + 25; // Starting position for the first bar

    for (const auto& breed : breeds) {
        // Calculate the center position of the current bar
        int barCenter = x + barWidth / 2;

        // Calculate the starting position for the text to center it with the bar
        int textX = barCenter - fm.horizontalAdvance(QString::fromStdString(breed.first)) / 2;
        int textY = chartHeight - 6;

        // Draw the breed label at the adjusted position
        painter.drawText(textX, textY, QString::fromStdString(breed.first));

        // Move to the next bar
        x += barWidth + spaceBetweenBars;
    }

    // Set up font for count numbers
    QFont countFont("Verdana", 8);
    painter.setFont(countFont);

    // Set pen color to blue for count numbers
    QPen blackPen(Qt::black);
    painter.setPen(blackPen);

    // Draw count numbers on the left side of the chart
    x = maxLabelWidth - 10;
    for (int i = 0; i <= maxCount + 4; i++) {
        // Draw the count number
        painter.drawText(x, chartHeight - 20 - i * 44, QString::number(i));

        // Draw dotted lines to the right of the numbers
        QPen dottedPen(Qt::black);
        dottedPen.setStyle(Qt::DotLine);
        painter.setPen(dottedPen);
        painter.drawLine(x + maxDigitWidth + 2, chartHeight - 20 - i * 44, chartWidth - 10, chartHeight - 20 - i * 44);
    }

    // Draw bars
    x = maxLabelWidth + 35;
    for (const auto& breed : breeds) {
        // Generate a random color for the bar
        QColor randomColor = QColor::fromRgb(
                QRandomGenerator::global()->bounded(256),
                QRandomGenerator::global()->bounded(256),
                QRandomGenerator::global()->bounded(256)
        );

        // Set up pen with the random color for drawing the bar
        QPen pen(randomColor);
        pen.setWidth(barWidth);
        painter.setPen(pen);

        // Calculate bar height
        float barHeight = breed.second * 44 - 12;

        // Draw the bar
        painter.drawLine(x, chartHeight - 30, x, chartHeight - 20 - barHeight);

        // Update x position for the next bar
        x += barWidth + spaceBetweenBars;
    }

    painter.end(); // End painting on the pixmap

    // Create a label to display the pixmap
    QLabel* label = new QLabel(window);
    label->setPixmap(pixmap);

    mainLayout->addWidget(label);
    window->setLayout(mainLayout);

    window->show();
}

void GUI::execute_undo() {
    try {
        service.undo();
        populateList();
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Warning", e.what());
    }
}

void GUI::execute_redo() {
    try {
        service.redo();
        populateList();
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Warning", e.what());
    }
}

void GUI::viewAdoptionList() {
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Adoption List");

    QVBoxLayout* layout = new QVBoxLayout(dialog);
    QTableView* adoptionListView = new QTableView(dialog);

    adoptionListModel = new AdoptionListModel(adoption_service.get_adoption_list(), this);
    adoptionListView->setModel(adoptionListModel);
    adoptionListView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    layout->addWidget(adoptionListView);
    dialog->setLayout(layout);
    dialog->resize(600, 400);
    dialog->exec();
}

