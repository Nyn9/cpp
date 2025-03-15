#include "AForm.hpp"

AForm::AForm() : m_name("default"), m_isSigned(false), m_gradeToSign(150), m_gradeToExecute(150)
{

}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &cp) : m_name(cp.m_name), m_isSigned(cp.m_isSigned), m_gradeToSign(cp.m_gradeToSign), m_gradeToExecute(cp.m_gradeToExecute)
{
    *this = cp;
}

AForm::~AForm()
{

}

AForm &AForm::operator=(AForm const &src)
{
	if (this != &src)
		m_isSigned = src.m_isSigned;
	return *this;
}

std::string AForm::getName() const
{
	return m_name;
}

bool AForm::getIsSigned() const
{
	return m_isSigned;
}

int AForm::getGradeToSign() const
{
	return m_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return m_gradeToExecute;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (m_isSigned)
	{
		std::cout << b.getName() << " couldn't sign " << m_name << " because it's already signed" << std::endl;
		return ;
	}
	if (b.getGrade() > m_gradeToSign)
	{
		std::cout << b.getName() << " couldn't sign " << m_name << " because ";
		throw AForm::GradeTooLowException();
	}
	m_isSigned = true;
	std::cout << b.getName() << " signed " << m_name << std::endl;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!m_isSigned)
	{
		std::cout << executor.getName() << " couldn't execute " << m_name << " because ";
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > m_gradeToExecute)
	{
		std::cout << executor.getName() << " couldn't execute " << m_name << " because ";
		throw AForm::GradeTooLowException();
	}
	std::cout << executor.getName() << " executed " << m_name << std::endl;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &o, AForm const &src)
{
	o << "Form " << src.getName() << " needs grade " << src.getGradeToSign() << " to be signed and grade " << src.getGradeToExecute() << " to be executed and is ";
	if (!src.getIsSigned())
		o << "not ";
	o << "signed";
	return o;
}
