#include <iostream>
#include "iter.hpp"

class Awesome
{
	public:
		Awesome(void) : _n(42) { return; }
		int get(void) const { return this->_n; }
	private:
		int _n;
};

std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { 
    o << rhs.get(); 
    return o; 
}


int main( void )
{
	Awesome a[5];

    iter(a, 5, print);
	std::cout << std::endl;

	int	array[] = {0, 1, 2, 3, 4};

	std::cout << "print:" << std::endl;
	::iter(array, 5, print<int>);
	std::cout << "print_square:" << std::endl;
	::iter(array, 5, print_square);
	std::cout << "print_double:" << std::endl;
	::iter(array, 5, print_double);

	std::cout << std::endl;

	float	array2[] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f};
	std::cout << "print:" << std::endl;
	::iter(array2, 5, print<float>);
	std::cout << "print_square:" << std::endl;
	::iter(array2, 5, print_square);
	std::cout << "print_double:" << std::endl;
	::iter(array2, 5, print_double);
	return 0;
}