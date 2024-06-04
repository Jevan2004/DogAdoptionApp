#include "AdoptionListCsvRepo.h"
#include <fstream>
#include "RepositoryException.h" // Assuming you have a FileException class defined

void AdoptionListCsvRepo::saveToFile(const std::string &filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw FileException("Error opening CSV file for writing: " + filename);
    }

    for(const auto& pet : AdoptionListMemoryRepo::adoption_list) {
        file << pet;
    }

    file.close();
}

void AdoptionListCsvRepo::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw FileException("Error opening CSV file for reading: " + filename);
    }

    AdoptionListMemoryRepo::adoption_list.clear();
    Pets pet;
    while(file >> pet) {
        AdoptionListMemoryRepo::adoption_list.push_back(pet);
    }

    file.close();
}

void AdoptionListCsvRepo::add_pet(const Pets &pet) {
    AdoptionListMemoryRepo::add_pet(pet);
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        throw FileException("Error opening CSV file for appending: " + filename);
    }

    file << pet;
    file.close();
}

void AdoptionListCsvRepo::clear_repo() {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw FileException("Error opening CSV file for clearing: " + filename);
    }

    file.close();
    AdoptionListMemoryRepo::clear_repo();
}
