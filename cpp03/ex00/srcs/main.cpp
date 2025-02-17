#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap("Clappy");

	claptrap.attack("Bandit");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	claptrap.attack("Bandit");
	claptrap.takeDamage(15);
	claptrap.beRepaired(3);
	claptrap.attack("Bandit");
	return 0;
}