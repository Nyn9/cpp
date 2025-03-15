#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &cp)
{
    *this = cp;
}

Intern::~Intern()
{

}

Intern &Intern::operator=(Intern const &src)
{
	(void)src;
	return *this;
}

AForm *Intern::createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string formName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*func[3])(std::string target) = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};
	for(int i = 0; i < 3; i++)
	{
		if (formName[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*func[i])(target);
		}
	}
	std::cout << "Intern can't create " << name << " form because this ";
	throw Intern::FormDontExist();
}

const char* Intern::FormDontExist::what() const throw()
{
	return "Form dont't exist";
}