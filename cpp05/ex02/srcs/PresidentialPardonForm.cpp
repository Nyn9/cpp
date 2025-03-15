#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cp) : AForm(cp)
{
    *this = cp;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (this != &src)
		AForm::operator=(src);
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}