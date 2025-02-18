#include <iostream>
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond("Diappy");

	diamond.attack("Fraggy");
	diamond.takeDamage(20);
	diamond.beRepaired(3);
	diamond.attack("Scappy");
	diamond.takeDamage(30);
	diamond.beRepaired(10);
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();

	return 0;
}