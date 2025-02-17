#include <iostream>
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scavtrap("Scappy");

	scavtrap.attack("Bandit");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(3);
	scavtrap.attack("Bandit");
	scavtrap.takeDamage(15);
	scavtrap.beRepaired(3);
	scavtrap.attack("Bandit");
	scavtrap.guardGate();

	return 0;
}