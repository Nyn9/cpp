#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &cp);
        virtual ~Dog();
        Dog &operator=(Dog const &src);

    protected:

};

#endif