#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &cp);

        virtual ~Ice();

        Ice &operator=(Ice const &src);

		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);

};

#endif 