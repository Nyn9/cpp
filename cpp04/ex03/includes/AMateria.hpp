#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "Character.hpp"

class ICharacter;
#include "ICharacter.hpp"

class AMateria
{
    public:
		AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &cp);

        virtual ~AMateria();

        AMateria &operator=(AMateria const &src);

        std::string const &getType() const;
		int getIsEquiped() const;
		void setIsEquiped(int isequiped);

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);

    protected:
        std::string m_type;
		int m_isequiped;

};

#endif 