#include <string>
#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}

void randomChump( std::string name )
{
	Zombie zombie = Zombie(name);
	zombie.announce();
}

int main()
{
	Zombie *tony = newZombie("Tony");
	tony->announce();
	randomChump("Many");
	delete tony;
	return 0;
}