#include <iostream>
#include "RPN.hpp"

/*

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
=> 42

./RPN "7 7 * 7 -"
=> 42

./RPN "1 2 * 2 / 2 * 2 4 - +"
=> 0

*/

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
