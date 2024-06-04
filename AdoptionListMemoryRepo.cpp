#include "AdoptionListMemoryRepo.h"
#include <fstream>

void AdoptionListMemoryRepo::add_pet(const Pets &pet) {
    adoption_list.push_back(pet);
//    saveToFile("animals_adoption");
}
