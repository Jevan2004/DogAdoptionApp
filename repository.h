#include <vector>
#include <string>
#include "pets_domain.h"
#include <iostream>
#pragma once

class Repository
{
public:
    virtual std::vector<Pets>& getPetsList() = 0;

    virtual int add_pet_to_repository(const Pets& pet) = 0;

    virtual int remove_pet_from_repository(int index) = 0;

    virtual int update_pet_from_repository(int index, const Pets& new_pet) = 0;

    virtual int get_repo_length() const = 0;

    virtual Pets get_pet_from_given_position(int index) = 0;

    virtual int search_for_a_pet(Pets pet) = 0;

    virtual void saveToFile(const std::string& filename) = 0;

    virtual void loadFromFile(const std::string& filename) = 0;

    virtual void clear_repo() = 0;

    virtual std::string get_file_name() = 0;

    virtual std::string get_repo_type() = 0;

    virtual ~Repository() = default;
};