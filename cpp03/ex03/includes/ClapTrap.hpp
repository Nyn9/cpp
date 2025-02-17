#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap();
		ClapTrap(std::string name);
        ClapTrap(const ClapTrap &cp);

        virtual ~ClapTrap();

        ClapTrap &operator=(ClapTrap const &src);

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

    protected:
		std::string m_name;
		int m_hitpoints;
		int m_energyPoints;
		int m_attackDamage;
};

#endif