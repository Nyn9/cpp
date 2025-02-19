#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &cp);
        virtual ~Dog();
        Dog &operator=(Dog const &src);

    protected:
		Brain *m_brain;

};

#endif