#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	{
		try
		{
			Bureaucrat b("Mark S.", 1);
			ShrubberyCreationForm f("Home");

			std::cout << f << std::endl;
			b.signForm(f);
			std::cout << f << std::endl;
			b.executeForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat b("Helly R.", 1);
			RobotomyRequestForm f("Bender");

			std::cout << f << std::endl;
			b.signForm(f);
			std::cout << f << std::endl;
			b.executeForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat b("Dylan G.", 1);
			PresidentialPardonForm f("President");

			std::cout << f << std::endl;
			b.signForm(f);
			std::cout << f << std::endl;
			b.executeForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat b("Irving B.", 1);
			PresidentialPardonForm f("President");

			std::cout << f << std::endl;
			b.executeForm(f);
			std::cout << f << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat b("Peter K.", 20);
			PresidentialPardonForm f("President");

			std::cout << f << std::endl;
			b.signForm(f);
			std::cout << f << std::endl;
			b.executeForm(f);
			std::cout << f << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}