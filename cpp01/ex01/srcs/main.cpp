#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int N = 5;


	if (N < 1)
	{
		std::cout << "Invalid number of zombies" << std::endl;
		return 1;
	}
	Zombie *creeps = zombieHorde(N, "Creeps");
	for (int i = 0; i < N; i++)
		creeps[i].announce();
	delete [] creeps;
	return 0;
}