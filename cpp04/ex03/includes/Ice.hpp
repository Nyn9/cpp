#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &cp);

        virtual ~Ice();

        Ice &operator=(Ice const &src);
    protected:

};

#endif 