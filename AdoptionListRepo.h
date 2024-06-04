#include "pets_domain.h"
#include <vector>
#pragma once

class AdoptionListRepo {
private:
    std::vector<Pets> adoption_list;

public:

    virtual void add_pet(const Pets& pet) = 0;

    virtual std::vector<Pets> get_adoption_list() = 0;

    virtual void saveToFile(const std::string& filename) = 0;

    virtual void loadFromFile(const std::string& filename) = 0;

    virtual void clear_repo() = 0;

    virtual std::string get_file_name() = 0;

    virtual ~AdoptionListRepo() = default;

};

