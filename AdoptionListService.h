//
// Created by tanas on 4/9/2024.
//

#ifndef OOP_A4_5_JEVAN2004_IML_ADOPTIONLISTSERVICE_H
#define OOP_A4_5_JEVAN2004_IML_ADOPTIONLISTSERVICE_H
#include "AdoptionListRepo.h"

class AdoptionListService {

private:
    AdoptionListRepo& repo;

public:
    AdoptionListService(AdoptionListRepo& adoptionListRepo) : repo(adoptionListRepo){}

    ~AdoptionListService() = default;

    std::vector<Pets> get_adoption_list()
    {
        return repo.get_adoption_list();
    }

    void add_to_adoption_list(const Pets &pet);

    std::string get_file_name()
    {
        return repo.get_file_name();
    }

};


#endif //OOP_A4_5_JEVAN2004_IML_ADOPTIONLISTSERVICE_H
