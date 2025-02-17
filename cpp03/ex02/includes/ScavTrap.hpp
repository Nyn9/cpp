#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
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