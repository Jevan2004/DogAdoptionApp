#pragma once
#include <exception>
#include <string>

class FileException : public std::exception
{
protected:
    std::string message;
public:
    FileException(const std::string& msg);
    virtual const char* what();
};

class RepositoryException : public std::exception{
protected:
    std::string message;

public:
    RepositoryException();
    RepositoryException(const std::string& msg);
    virtual ~RepositoryException(){}
    virtual const char* what();
};

class DuplicatePetException : public RepositoryException
{
public:
    const char* what();
};

class InexistentPetExecption : public RepositoryException
{
public:
    const char* what();
};

#include <stdexcept>
#include <string>

class PetNotFoundException : public RepositoryException {
public:
    PetNotFoundException(const std::string& petName) : RepositoryException("Pet '" + petName + "' not found.") {}
};
