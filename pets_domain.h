    #pragma once
#include <string>

class Pets
        {
        private:
            std::string breed;
            std::string name;
            int age;
            std::string photograph;

            static int numberOfInstances;
        public:
            static int getNumberOfInstances();

            Pets(std::string name = "", std::string breed = "", int age = 0, std::string photograph = "");

            Pets(const Pets& p);

            ~Pets();

            std::string getName() const
            {
                return this->name;
            }

            std::string getBreed() const
            {
                return this->breed;
            }

            int getAge() const
            {
                return this->age;
            }

            std::string getPhotograph() const
            {
                return this->photograph;
            }

            Pets& operator=(const Pets& v);

            std::string toString();

            bool operator==(const Pets& pet) const;

            friend std::istream& operator>>(std::istream& stream, Pets& a);

            friend std::ostream& operator<<(std::ostream& stream, const Pets& a);

        };

