#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
		DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &cp);

        virtual ~DiamondTrap();

		void attack(std::string const & target);
		void whoAmI();

    private:
		std::string m_name;
};

#endif