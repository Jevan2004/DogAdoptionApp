#pragma once
#include "AdoptionListMemoryRepo.h"

class AdoptionListCsvRepo : public AdoptionListMemoryRepo{
private:

    std::string filename;

public:
    AdoptionListCsvRepo(const std:: string& filename) : filename(filename){
        AdoptionListCsvRepo::loadFromFile(filename);
    }

    void add_pet(const Pets& pet) override;

    std::vector<Pets> get_adoption_list() override
    {
        return AdoptionListMemoryRepo::get_adoption_list();
    }

    void clear_repo() override;

    void saveToFile(const std::string& filename) override;

    std::string get_file_name() override
    {
        return this->filename;
    }

    void loadFromFile(const std::string& filename) override;

    ~AdoptionListCsvRepo() override = default;
};
