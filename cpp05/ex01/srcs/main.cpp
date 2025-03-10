#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	{
		try
		{
			Bureaucrat b("Mark S.", 1);
			Form f("Form1", 1, 1);

			std::cout << f << std::endl;
			b.signForm(f);
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
			Bureaucrat b("Helly R.", 150);
			Form f("Form2", 45, 50);

			std::cout << f << std::endl;
			b.signForm(f);
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
			Bureaucrat b("Dylan G.", 45);
			Bureaucrat c("Irving B.", 50);
			Form f("Form3", 50, 50);

			std::cout << f << std::endl;
			b.signForm(f);
			std::cout << f << std::endl;
			c.signForm(f);
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
			Form f("Form3", 0, 0);

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
			Form f("Form4", 151, 151);

			std::cout << f << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}