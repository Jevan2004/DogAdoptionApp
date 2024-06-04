#include "MemoryRepo.h"
#include <string>
#include <fstream>
#include <iostream>
class TextFileRepo : public MemoryRepository {
private:
    std::string filename;  // Store the filename as a member variable

public:
    TextFileRepo(const std::string& filename) : filename(filename) {
        TextFileRepo::loadFromFile(filename);

    }  // Use const std::string& for constructor parameter

    int add_pet_to_repository(const Pets& pet) override;

    int remove_pet_from_repository(int index) override;

    int update_pet_from_repository(int index, const Pets& new_pet) override;

    int get_repo_length() const override { return pets_list.size(); }

    Pets get_pet_from_given_position(int index) override;

    int search_for_a_pet(Pets pet) override;

    std::vector<Pets>& getPetsList() override { return pets_list; }

    std::string get_file_name()
    {
        return this->filename;

    }

    std::string get_repo_type() override
    {
        return "text";
    }

    void clear_repo() override;

    void saveToFile(const std::string& filename) override;

    void loadFromFile(const std::string& filename) override;

    ~TextFileRepo() override = default;
};