#include "MemoryRepo.h"
#include <stdexcept>
#include <fstream>
#include <algorithm>

int MemoryRepository::search_for_a_pet(const Pets pet) {
    auto it = std::find(pets_list.begin(), pets_list.end(), pet);
    if (it != pets_list.end()) {
        return std::distance(pets_list.begin(), it);
    }
    return -1;
}

Pets MemoryRepository::get_pet_from_given_position(int index) {
    if (index < 0 || index >= pets_list.size())
        throw std::out_of_range("No pet found at given position");

    int current_position = 0;
    for (const auto& current_pet : pets_list) {
        if (current_position == index)
            return current_pet;
        ++current_position;
    }
    throw std::out_of_range("No pet found at given position");
}

int MemoryRepository::add_pet_to_repository(const Pets& pet) {
    if (search_for_a_pet(pet) != -1)
        throw DuplicatePetException(); // Pet already exists

    pets_list.push_back(pet);
    return 0;
}

int MemoryRepository::remove_pet_from_repository(int index) {
//    if (index < 0 || index >= pets_list.size())
//        throw std::out_of_range("Pula");

    pets_list.erase(pets_list.begin() + index);

    return 0;
}

int MemoryRepository::update_pet_from_repository(int index, const Pets& new_pet) {
    if (index < 0 || index >= pets_list.size())
        throw std::out_of_range("Index out of range");

    pets_list[index] = new_pet;
    return 0;
}
