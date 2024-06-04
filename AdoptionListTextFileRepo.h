#pragma once
#include "AdoptionListMemoryRepo.h"

class AdoptionListTextFileRepo: public AdoptionListMemoryRepo {
private:
    std::string filename;
public:
    AdoptionListTextFileRepo(const std::string& filename) : filename(filename){
        AdoptionListTextFileRepo::loadFromFile(filename);
    }
    void add_pet(const Pets& pet) override;

    std::vector<Pets> get_adoption_list() override
    {
        return AdoptionListMemoryRepo::get_adoption_list();
    }

    void clear_repo() override;

    std::string get_file_name() override
    {
        return this->filename;
    }

    void saveToFile(const std::string& filename) override;

    void loadFromFile(const std::string& filename) override;

};

