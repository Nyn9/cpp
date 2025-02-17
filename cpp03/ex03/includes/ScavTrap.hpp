#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
		ScavTrap(std::string name);
        ScavTrap(const ScavTrap &cp);

        ~ScavTrap();

		void attack(std::string const & target);
		void guardGate();
};

#endif