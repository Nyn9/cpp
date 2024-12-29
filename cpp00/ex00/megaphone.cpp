#include <iostream>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int j = 1; j < ac; j++)
		for (int i = 0; av[j][i]; i++)
			std::cout << (char)toupper(av[j][i]);
	std::cout << std::endl;
	return (0);
}