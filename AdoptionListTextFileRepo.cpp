#include "AdoptionListTextFileRepo.h"
#include <fstream>
#include "RepositoryException.h"

void AdoptionListTextFileRepo::saveToFile(const std::string &filename) {
    std::ofstream file(filename);
    if(file.is_open()){
        for(const auto& pet: adoption_list)
        {
            file << pet;
        }
        file.close();
    }
    else
        throw FileException("Error opening HTML file for writing: " + filename);
}

void AdoptionListTextFileRepo::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);

    if(file.is_open()){
        adoption_list.clear();
        Pets pet;
        while(file >> pet)
        {
            adoption_list.push_back(pet);
        }
        file.close();
    }
    else
        throw FileException("Error opening HTML file for writing: " + filename);
}

void AdoptionListTextFileRepo::add_pet(const Pets &pet) {
    AdoptionListMemoryRepo::add_pet(pet);
    std::ofstream file(filename, std::ios::app);
    if(file.is_open())
    {
        file << pet;
        file.close();
    }

}

void AdoptionListTextFileRepo::clear_repo() {
    std::ofstream file(filename);

    if(file.is_open())
    {
        file.close();
    }
    AdoptionListMemoryRepo::clear_repo();
}

