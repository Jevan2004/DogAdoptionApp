#include "CsvFileRepo.h"
#include <fstream>
#include "RepositoryException.h"

void CsvFileRepo::saveToFile(const std::string &filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw FileException("Error opening CSV file for writing: " + filename);
    }

    for (const auto& pet : pets_list) {
        file << pet;
    }

    file.close();
}

void CsvFileRepo::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw FileException("Error opening CSV file for reading: " + filename);
    }

    pets_list.clear();
    Pets pet;
    while (file >> pet) {
        pets_list.push_back(pet);
    }

    file.close();
}

int CsvFileRepo::search_for_a_pet(Pets pet) {
    loadFromFile(filename);
    return MemoryRepository::search_for_a_pet(pet);
}

int CsvFileRepo::add_pet_to_repository(const Pets &pet) {
    int res = MemoryRepository::add_pet_to_repository(pet);
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        throw FileException("Error opening CSV file for appending: " + filename);
    }
    file << pet;
    file.close();
    return res;
}

int CsvFileRepo::remove_pet_from_repository(int index) {
    loadFromFile(filename);
    int res =  MemoryRepository::remove_pet_from_repository(index);
    saveToFile(filename);
    return res;
}

int CsvFileRepo::update_pet_from_repository(int index, const Pets &new_pet) {
    loadFromFile(filename);
    int res =  MemoryRepository::update_pet_from_repository(index, new_pet);
    saveToFile(filename);
    return res;
}

Pets CsvFileRepo::get_pet_from_given_position(int index) {
    loadFromFile(filename);
    return MemoryRepository::get_pet_from_given_position(index);
}

void CsvFileRepo::clear_repo() {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw FileException("Error opening CSV file for clearing: " + filename);
    }

    file.close();
    MemoryRepository::clear_repo();
}
