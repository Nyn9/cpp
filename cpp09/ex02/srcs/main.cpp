#include <iostream>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Not enough arguments" << std::endl;
		return (1);
	}
	PmergeMe pmerge(av);
}