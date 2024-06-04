#include "AdoptionListHtmlRepo.h"
#include <fstream>
#include <iostream>
#include "RepositoryException.h"
void AdoptionListHtmlRepo::add_pet(const Pets &pet) {
    AdoptionListMemoryRepo::add_pet(pet);
    saveToFile(filename);
}

void AdoptionListHtmlRepo::saveToFile(const std::string &filename) {
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

        for(const auto & pet : AdoptionListMemoryRepo::adoption_list)
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
        throw FileException("Error opening HTML file for writing: " + filename);
}

void AdoptionListHtmlRepo::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    AdoptionListMemoryRepo::adoption_list.clear();
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
            break;
        }

        std::string name, breed, photo_link, age_string;
        int age;
        std::getline(file, buffer);

        unsigned long long end_index;
        end_index = buffer.find("</td>");
        name = buffer.substr(4, end_index - 4);

        std::getline(file, buffer);
        end_index = buffer.find("</td>");
        breed = buffer.substr(4, end_index - 4);

        std::getline(file, buffer);
        end_index = buffer.find("</td>");
        age_string = buffer.substr(4, end_index - 4);
//        std::cout << age_string << '\n';
        age = std::stoi(age_string);

        std::getline(file, buffer);
        end_index = buffer.find("\">Link");
        photo_link = buffer.substr(13, end_index - 13);

        Pets new_pet(name, breed, age, photo_link);
        AdoptionListMemoryRepo::adoption_list.push_back(new_pet);
        std::getline(file, buffer);

    }}

void AdoptionListHtmlRepo::clear_repo() {
    std::ofstream file(filename);

    if(file.is_open())
    {
        file.close();
    }
    AdoptionListMemoryRepo::clear_repo();
}
