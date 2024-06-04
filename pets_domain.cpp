#include "pets_domain.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

int Pets::numberOfInstances = 0;

int Pets::getNumberOfInstances()
{
    return numberOfInstances;
}

Pets::Pets(std::string name, std::string breed, int age, std::string photograph): name{ name }, breed{ breed }, age{ age }, photograph { photograph }
{
    numberOfInstances++;
}

Pets::Pets(const Pets &p)
{
    this->name = p.name;
    this->breed = p.breed;
    this->age = p.age;
    this->photograph = p.photograph;
}

Pets::~Pets()
{
    //std::cout << " Destructor\n";
    numberOfInstances--;
}

std::string Pets::toString()
{
    std::stringstream txt;
    txt << "Name:" << this->name << "| Breed:" << this->breed << "|Age:" << this->age << "|Photography:" << this->photograph << std::endl;
    return txt.str();
}

Pets& Pets::operator=(const Pets &v){
    this->name = v.name;
    this->breed = v.breed;
    this->age = v.age;
    this->photograph = v.photograph;
    return *this;
}


bool Pets::operator==(const Pets &pet) const{
    return this->name == pet.name && this->breed == pet.breed; //&&
            //this->age == pet.age && this->photograph == pet.photograph;
}

std::istream &operator>>(std::istream &stream, Pets &a) {
    //return <#initializer#>;
    std::getline(stream,a.name, ',');
    std::getline(stream,a.breed, ',');
    stream >> a.age;
    stream.ignore();
    std::getline(stream,a.photograph);
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const Pets &a) {
    stream << a.name << "," << a.breed << "," << a.age << "," << a.photograph << std::endl;
    return stream;
}

