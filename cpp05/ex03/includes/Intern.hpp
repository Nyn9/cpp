#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &cp);

        virtual ~Intern();

        Intern &operator=(Intern const &src);

		AForm *makeForm(std::string name, std::string target);

		class FormDontExist : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		AForm *createShrubberyCreationForm(std::string target);
		AForm *createRobotomyRequestForm(std::string target);
		AForm *createPresidentialPardonForm(std::string target);

};

#endif