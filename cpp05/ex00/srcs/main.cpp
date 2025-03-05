#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat b1("Tony", 1);
		Bureaucrat b2("Many", 150);
		Bureaucrat b3("Sosa", 0);
		Bureaucrat b4("Rebenga", 151);

		std::cout << "Name : " << b1.getName() << " Grade : " << b1.getGrade() << std::endl;
		std::cout << "Name : " << b2.getName() << " Grade : " << b2.getGrade() << std::endl;
		std::cout << "Name : " << b3.getName() << " Grade : " << b3.getGrade() << std::endl;
		std::cout << "Name : " << b4.getName() << " Grade : " << b4.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}