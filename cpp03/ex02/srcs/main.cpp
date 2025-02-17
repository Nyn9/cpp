#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap scavtrap("Scappy");
	FragTrap fragtrap("Fraggy");

	scavtrap.attack("Fraggy");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(3);
	fragtrap.attack("Scappy");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(10);
	scavtrap.guardGate();
	fragtrap.highFivesGuys();

	return 0;
}