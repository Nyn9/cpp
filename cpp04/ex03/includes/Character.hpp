#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <vector>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character();
        Character(std::string name);
        Character(const Character &cp);

        virtual ~Character();

        Character &operator=(Character const &src);

		virtual std::string const &getName() const;

		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

    protected:
        std::string m_name;
		static std::vector<AMateria*> m_trash;

};

#endif 