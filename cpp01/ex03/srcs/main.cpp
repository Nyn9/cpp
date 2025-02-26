#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA tony("Tony", club);

		tony.attack();
		club.setType("some other type of club");
		tony.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB many("Many");

		many.attack();
		many.setWeapon(club);
		many.attack();
		club.setType("some other type of club");
		many.attack();
	}
	return 0;
}