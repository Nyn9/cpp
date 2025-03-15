#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main(void)
{
	{
		try
		{
			Bureaucrat b("Mark S.", 1);
			Intern i;
			AForm *f = i.makeForm("shrubbery creation", "Home");

			std::cout << *f << std::endl;
			b.signForm(*f);
			std::cout << *f << std::endl;
			b.executeForm(*f);
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
			Intern i;
			AForm *f = i.makeForm("robotomy request", "Bender");

			std::cout << *f << std::endl;
			b.signForm(*f);
			std::cout << *f << std::endl;
			b.executeForm(*f);
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
			Intern i;
			AForm *f = i.makeForm("presidential pardon", "President");

			std::cout << *f << std::endl;
			b.signForm(*f);
			std::cout << *f << std::endl;
			b.executeForm(*f);
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
			Intern i;
			AForm *f = i.makeForm("presidential pardon", "President");

			std::cout << *f << std::endl;
			b.executeForm(*f);
			std::cout << *f << std::endl;
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
			Intern i;
			AForm *f = i.makeForm("presidential pardon", "President");

			std::cout << *f << std::endl;
			b.signForm(*f);
			std::cout << *f << std::endl;
			b.executeForm(*f);
			std::cout << *f << std::endl;
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
			Intern i;
			AForm *f = i.makeForm("Mysterious and Important", "President");

			std::cout << *f << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}