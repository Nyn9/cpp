#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &cp);
        ~Cat();
        Cat &operator=(Cat const &src);

    protected:

};

#endif