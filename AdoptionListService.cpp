//
// Created by tanas on 4/9/2024.
//

#include "AdoptionListService.h"

void AdoptionListService::add_to_adoption_list(const Pets &pet) {
    repo.add_pet(pet);
}

