#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &cp);

        virtual ~Cat();

        Cat &operator=(Cat const &src);

        virtual void makeSound() const;
};

#endif