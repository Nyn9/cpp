#include <string>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}

int main()
{
	int n = 20;
	Zombie *creeps = zombieHorde(n, "Creeps");
	for (int i = 0; i < n; i++)
		creeps[i].announce();
	delete [] creeps;
	return 0;
}