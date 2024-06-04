#pragma once
#include <string>
#include <vector>
#include "pets_domain.h"
#include "repository.h"
#include "RepositoryException.h"

class MemoryRepository: public  Repository
{
protected:
    std::vector<Pets> pets_list;

public:
    MemoryRepository() = default;

    ~MemoryRepository() override = default;

    int add_pet_to_repository(const Pets& pet) override;

    int remove_pet_from_repository(int index) override;

    int update_pet_from_repository(int index, const Pets& new_pet) override;

    int get_repo_length() const override
    {
        return pets_list.size();
    }

    Pets get_pet_from_given_position(int index) override;

    int search_for_a_pet(Pets pet) override;

    std::vector<Pets>& getPetsList()  override{
        return pets_list;
    }

    void clear_repo() override
    {
        this->pets_list.clear();
    }

    std::string get_file_name() override
    {
        return "";
    }

    std::string get_repo_type() override
    {
        return "memory";
    }
    void saveToFile(const std::string& filename) override{}

    void loadFromFile(const std::string& filename) override{}

};