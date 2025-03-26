#include <iostream>
#include "iter.hpp"

int main( void )
{
	int	array[] = {1, 2, 3, 4};

	std::cout << "print:" << std::endl;
	::iter(array, 4, print<int>);
	std::cout << "print_square:" << std::endl;
	::iter(array, 4, print_square);
	std::cout << "print_double:" << std::endl;
	::iter(array, 4, print_double);

	std::cout << std::endl;

	float	array2[] = {1.1f, 2.2f, 3.3f, 4.4f};
	std::cout << "print:" << std::endl;
	::iter(array2, 4, print<float>);
	std::cout << "print_square:" << std::endl;
	::iter(array2, 4, print_square);
	std::cout << "print_double:" << std::endl;
	::iter(array2, 4, print_double);
	return 0;
}