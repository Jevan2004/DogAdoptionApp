#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include "MemoryRepo.h"
#include "Service.h"
#include "gui1.h"
#include "RepoType.h"
#include "TextFileRepo.h"
#include "AdoptionListTextFileRepo.h"
#include "CsvFileRepo.h"
#include "AdoptionListCsvRepo.h"
#include "HtmlRepo.h"
#include "AdoptionListHtmlRepo.h"
#include "MemoryRepo.h"
#include "AdoptionListMemoryRepo.h"
#include "load.h"
#include "main_modes.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QDialog dialog;
    dialog.setWindowTitle("Repository Type Selection");

    RepoType repoType;
    QVBoxLayout layout(&dialog);
    layout.addWidget(&repoType);

    Repository* repo = nullptr;
    AdoptionListRepo* adoptionListRepo = nullptr;
    QObject::connect(&repoType, &RepoType::csvSelected, [&]() {
        repo = new CsvFileRepo("animals.csv");
        adoptionListRepo = new AdoptionListCsvRepo("adoption_list.csv");
        dialog.accept();
    });
    QObject::connect(&repoType, &RepoType::htmlSelected, [&]() {
        repo = new HtmlRepo("animals.html");
        adoptionListRepo = new AdoptionListHtmlRepo("adoption_list.html");
        dialog.accept();
    });
    QObject::connect(&repoType, &RepoType::textFileSelected, [&]() {
        repo = new TextFileRepo("animals.txt");
        adoptionListRepo = new AdoptionListTextFileRepo("adoption_list.txt");
        dialog.accept();
    });
    QObject::connect(&repoType, &RepoType::memorySelected, [&]() {
        repo = new MemoryRepository();
        adoptionListRepo = new AdoptionListMemoryRepo();
        dialog.accept();
    });

    if (dialog.exec() != QDialog::Accepted) {
        return 0;
    }

    Service service(repo);
    AdoptionListService adoptionListService(*adoptionListRepo);

    QDialog load_dialog;
    load_dialog.setWindowTitle("Load Data");
    QVBoxLayout layout_load(&load_dialog);


    load load_ui;
    layout_load.addWidget(&load_ui);

    QObject::connect(&load_ui, &load::load_data_selected, [&](){
        load_dialog.accept();
    });

    QObject::connect(&load_ui, &load::dont_load_data_selected, [&](){
        repo->clear_repo();
        service.initialize_repo();
        adoptionListRepo->clear_repo();
        load_dialog.accept();

    });

    if (load_dialog.exec() != QDialog::Accepted) {
        return 0;
    }

    main_modes mainModes(service,adoptionListService);
    mainModes.show();

    return app.exec();
}
