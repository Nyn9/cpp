
#include "easyfind.hpp"

int main( void )
{
	std::vector<int> v;
	std::list<int> l;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		l.push_back(i);
	}


	try
	{
		std::cout << "easyfind(v, 5) = " << *easyfind(v, 5) << std::endl;
		std::cout << "easyfind(v, 11) = " << *easyfind(v, 11) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "------------------------" << std::endl;

	try
	{
		std::cout << "easyfind(l, 5) = " << *easyfind(l, 5) << std::endl;
		std::cout << "easyfind(l, 11) = " << *easyfind(l, 11) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}