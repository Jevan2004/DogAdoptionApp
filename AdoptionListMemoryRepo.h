#include "pets_domain.h"
#include <vector>
#include "AdoptionListRepo.h"
#pragma once

class AdoptionListMemoryRepo: public AdoptionListRepo  {
protected:
    std::vector<Pets> adoption_list;

public:
    AdoptionListMemoryRepo() = default;

    ~AdoptionListMemoryRepo() override = default ;

    void add_pet(const Pets& pet)  override;

    std::vector<Pets> get_adoption_list() override
    {
        return this->adoption_list;
    }

    void clear_repo() override
    {
        this->adoption_list.clear();
    }

    std::string get_file_name() override
    {
        return "";
    }
    void saveToFile(const std::string& filename) override {};

    void loadFromFile(const std::string& filename) override {};
};
