//
// Created by tanas on 5/13/2024.
//

#include "RepositoryException.h"

RepositoryException::RepositoryException() : exception{}, message{""}
{
}

RepositoryException::RepositoryException(const std::string &msg): message(msg) {

}

const char *RepositoryException::what() {
    return this->message.c_str();
}


const char *DuplicatePetException::what() {
    return "This pet already exists";
}


const char *InexistentPetExecption::what() {
    return "This pet does not exist!!";
}

FileException::FileException(const std::string &msg) : message(msg) {
}

const char *FileException::what() {
    return message.c_str();
}
