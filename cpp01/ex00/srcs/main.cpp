#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	Zombie *tony = newZombie("Tony");
	tony->announce();
	randomChump("Many");
	delete tony;
	return 0;
}