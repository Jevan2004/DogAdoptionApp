#include "HtmlRepo.h"
#include <fstream>

void HtmlRepo::saveToFile(const std::string &filename) {
    std::ofstream file(filename);

    if(file.is_open())
    {
        file << "<!DOCTYPE html>\n";
        file << "<html>\n";
        file << "<head>\n";
        file << "<title>Pets</title>\n";
        file << "</head>\n";
        file << "<body>\n";
        file << "<table border=\"1\">\n";
        file << "<tr>\n";
        file << "<td>Name</td>\n";
        file << "<td>Breed</td>\n";
        file << "<td>Age</td>\n";
        file << "<td>Photograph Link</td>\n";
        file << "</tr>\n";

        for(const auto & pet : MemoryRepository::pets_list)
        {
            file << "<tr>\n";
            file << "<td>" << pet.getName() << "</td>\n";
            file << "<td>" << pet.getBreed() << "</td>\n";
            file << "<td>" << pet.getAge() << "</td>\n";
            file << "<td><a href=\"" << pet.getPhotograph() << "\">Link</a></td>\n";
            file << "</tr>\n";
        }
        file << "</table>\n";
        file << "</body>\n";
        file << "</html>\n";

        file.close();
    }
    else
    {
        throw FileException("Error opening HTML file for writing: " + filename);

    }
}

int HtmlRepo::add_pet_to_repository(const Pets &pet) {
    int res = MemoryRepository::add_pet_to_repository(pet);
    saveToFile(filename);
    return res;
}

int HtmlRepo::remove_pet_from_repository(int index) {
    loadFromFile(filename);
    int res =  MemoryRepository::remove_pet_from_repository(index);
    saveToFile(filename);
    return res;
}

int HtmlRepo::update_pet_from_repository(int index, const Pets &new_pet) {
    loadFromFile(filename);
    int res =  MemoryRepository::update_pet_from_repository(index, new_pet);
    saveToFile(filename);
    return res;
}

Pets HtmlRepo::get_pet_from_given_position(int index) {
    loadFromFile(filename);
    return MemoryRepository::get_pet_from_given_position(index);
}

int HtmlRepo::search_for_a_pet(Pets pet) {
    loadFromFile(filename);
    return MemoryRepository::search_for_a_pet(pet);
}

void HtmlRepo::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    MemoryRepository::pets_list.clear();
    int index = 12;
    std::string buffer;
    if(!file.is_open())
        throw FileException("Error opening HTML file for writing: " + filename);

    while( std::getline(file, buffer) && index != 0)
    {
        index--;
    }
    while(std::getline(file, buffer))
    {

        if(buffer.find("</table>") != std::string::npos)
        {
//            std::cout << buffer.find("table>");
            break;
        }

        std::string name, breed, photo_link, age_string;
        int age;
        std::getline(file, buffer);

        unsigned long long end_index;
        end_index = buffer.find("</td>");
        name = buffer.substr(4, end_index - 4);

//        std::cout << name << '\n';

        std::getline(file, buffer);
        end_index = buffer.find("</td>");
        breed = buffer.substr(4, end_index - 4);

//        std::cout << breed << '\n';

        std::getline(file, buffer);

        end_index = buffer.find("</td>");
        age_string = buffer.substr(4, end_index - 4);
//        std::cout << "cp" << age_string << "cp\n";

        age = std::stoi(age_string);
//        std::cout << age << '\n';

        std::getline(file, buffer);
        end_index = buffer.find("\">Link");
        photo_link = buffer.substr(13, end_index - 13);
//        std::cout << photo_link << '\n';
        Pets new_pet(name, breed, age, photo_link);
        MemoryRepository::pets_list.push_back(new_pet);
        std::getline(file, buffer);

    }
    while(std::getline(file, buffer))
    {}
    file.close();
}

void HtmlRepo::clear_repo() {
    std::ofstream file(filename);

    if(file.is_open())
    {
        file.close();
    }
    MemoryRepository::clear_repo();
}
