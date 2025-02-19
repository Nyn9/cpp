#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &cp);

        ~WrongCat();

        WrongCat &operator=(WrongCat const &src);

    protected:

};

#endif