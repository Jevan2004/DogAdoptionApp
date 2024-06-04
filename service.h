#pragma once

#include <memory>
#include "repository.h"
#include "RepositoryException.h"
#include "Action.h"

class Service
{
private:
    Repository* repo;
    std::vector<Action*> undo_stack;
    std::vector<Action*> redo_stack;
    void clear_redo_stack() {
        for (Action* action : redo_stack) {
            delete action;
        }
        redo_stack.clear();
    }
public:
    Service(Repository* repository) : repo(repository) {}

    ~Service() {
        for (Action* action : undo_stack) {
            delete action;
        }
        for (Action* action : redo_stack) {
            delete action;
        }
    }

    int add_pet_service(std::string name, std::string breed, int age, std::string photograph);

    int remove_pet_service(int index);

    int update_pet_service(int index, const Pets& new_pet);

    int verify_if_it_exists(std::string name, std::string breed, int age, std::string photograph);

    std::vector<Pets> get_pets_by_breed_and_age(std::string breed, int age);

    std::vector<Pets> get_all_pets() const
    {
        return repo->getPetsList();
    }

    int get_position_of_pet(const Pets& new_pet){
        return repo->search_for_a_pet(new_pet);
    }

    int get_repo_length() const
    {
        return repo->get_repo_length();
    }

    std::string get_repo_type()
    {
        return repo->get_repo_type();
    }

    std::string get_repo_filename()
    {
        return repo->get_file_name();
    }
    void initialize_repo();
    void undo();
    void redo();
};
