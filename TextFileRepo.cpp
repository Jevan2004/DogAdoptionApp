#include <fstream>
#include "TextFileRepo.h"
using namespace std;

void TextFileRepo::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pet : pets_list) {

            file << pet;  // Assuming << operator is defined for Pets
        }
        file.close();
    }
    else
        throw FileException("Error opening text file for writing: " + filename);
}

void TextFileRepo::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        pets_list.clear();
        Pets pet;
        while (file >> pet) {
            pets_list.push_back(pet);

        }
        file.close();
    }
    else
        throw FileException("Error opening text file for loading: " + filename);

}

int TextFileRepo::add_pet_to_repository(const Pets &pet) {
    int res = MemoryRepository::add_pet_to_repository(pet);
    std::ofstream file(filename, std::ios::app); // Open file in append mode
    if (file.is_open()) {
            file << pet;  // Assuming << operator is defined for Pets
        file.close();
    }
    return res;
}

int TextFileRepo::remove_pet_from_repository(int index) {
    loadFromFile(filename);
    int res = MemoryRepository::remove_pet_from_repository(index);
    saveToFile(filename);
    return res;
}

int TextFileRepo::update_pet_from_repository(int index, const Pets &new_pet) {
    loadFromFile(filename);
    int res = MemoryRepository::update_pet_from_repository(index, new_pet);
    saveToFile(filename);
    return res;
}

Pets TextFileRepo::get_pet_from_given_position(int index) {
    loadFromFile(filename);
    return MemoryRepository::get_pet_from_given_position(index);
}

int TextFileRepo::search_for_a_pet(Pets pet) {
    loadFromFile(filename);
    int res = MemoryRepository::search_for_a_pet(pet);
    return res;
}

void TextFileRepo::clear_repo() {
    std::ofstream file(filename);

    if(file.is_open())
    {
        file.close();
    }
    MemoryRepository::clear_repo();
}
