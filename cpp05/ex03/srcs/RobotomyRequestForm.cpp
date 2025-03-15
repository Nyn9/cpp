#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cp) : AForm(cp)
{
    *this = cp;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (this != &src)
		AForm::operator=(src);
	return *this;
}

void RobotomyRequestForm::setTarget(std::string target)
{
	m_target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "*drilling noises* ";
	srand(time(NULL));
	if (rand() % 2)
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << getName() << " couldn't be robotomized" << std::endl;
}