#pragma once
#include "MemoryRepo.h"

class CsvFileRepo: public MemoryRepository{
private:
    std::string filename; // try to see if it works with &
public:
    CsvFileRepo(const std::string& filename) : filename(filename){
        CsvFileRepo::loadFromFile(filename);
    }

    int add_pet_to_repository(const Pets& pet) override;

    int remove_pet_from_repository(int index) override;

    int update_pet_from_repository(int index, const Pets& new_pet) override;

    int get_repo_length() const override { return pets_list.size(); }

    Pets get_pet_from_given_position(int index) override;

    int search_for_a_pet(Pets pet) override;

    std::vector<Pets>& getPetsList() override { return pets_list; }

    void clear_repo() override;

    std::string get_file_name() override
    {
        return this->filename;

    }

    std::string get_repo_type() override
    {
        return "csv";
    }

    void saveToFile(const std::string& filename) override;

    void loadFromFile(const std::string& filename) override;

    ~CsvFileRepo() override = default;
};

