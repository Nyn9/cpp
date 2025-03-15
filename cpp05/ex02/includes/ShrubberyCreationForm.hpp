#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &cp);

        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

		void execute(Bureaucrat const &executor) const;
};

#endif