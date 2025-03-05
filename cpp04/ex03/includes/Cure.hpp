#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure &cp);

        virtual ~Cure();

        Cure &operator=(Cure const &src);

		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};

#endif 