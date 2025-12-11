#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &cp);

        virtual ~Dog();

        Dog &operator=(Dog const &src);

        void makeSound() const;

    private:
		Brain *m_brain;
};

#endif