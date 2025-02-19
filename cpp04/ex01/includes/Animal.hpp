#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal();
        Animal(const Animal &cp);

        virtual ~Animal();

        Animal &operator=(Animal const &src);

		void makeSound() const;

		std::string getType() const;

    protected:
		std::string m_type;
};

#endif