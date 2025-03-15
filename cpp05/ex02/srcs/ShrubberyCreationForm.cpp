#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cp) : AForm(cp)
{
    *this = cp;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (this != &src)
		AForm::operator=(src);
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream file((getName() + "_shrubbery").c_str());
	file << "      /\\" << std::endl;
	file << "     /\\*\\" << std::endl;
	file << "    /\\O\\*\\" << std::endl;
	file << "   /*/\\/\\/\\" << std::endl;
	file << "  /\\O\\/\\*\\/\\" << std::endl;
	file << " /\\*\\/\\*\\/\\/\\" << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||" << std::endl;
	file << "      ||" << std::endl;
	file << "      ||" << std::endl;
	file.close();
}