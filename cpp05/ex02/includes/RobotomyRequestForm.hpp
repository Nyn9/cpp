#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &cp);

        virtual ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(RobotomyRequestForm const &src);

		void execute(Bureaucrat const &executor) const;
};

#endif