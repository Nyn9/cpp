#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &cp);

        virtual ~Cure();

        Cure &operator=(Cure const &src);

    protected:

};

#endif 