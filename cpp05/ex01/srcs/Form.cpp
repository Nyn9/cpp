#include "Form.hpp"

Form::Form() : m_name("default"), m_isSigned(false), m_gradeToSign(150), m_gradeToExecute(150)
{

}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : m_name(name), m_isSigned(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &cp) : m_name(cp.m_name), m_isSigned(cp.m_isSigned), m_gradeToSign(cp.m_gradeToSign), m_gradeToExecute(cp.m_gradeToExecute)
{
    *this = cp;
}

Form::~Form()
{

}

Form &Form::operator=(Form const &src)
{
	if (this != &src)
		m_isSigned = src.m_isSigned;
	return *this;
}

std::string Form::getName() const
{
	return m_name;
}

bool Form::getIsSigned() const
{
	return m_isSigned;
}

int Form::getGradeToSign() const
{
	return m_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return m_gradeToExecute;
}

void Form::beSigned(Bureaucrat &b)
{
	if (m_isSigned)
	{
		std::cout << b.getName() << " couldn't sign " << m_name << " because it's already signed" << std::endl;
		return ;
	}
	if (b.getGrade() > m_gradeToSign)
	{
		std::cout << b.getName() << " couldn't sign " << m_name << " because ";
		throw Form::GradeTooLowException();
	}
	m_isSigned = true;
	std::cout << b.getName() << " signed " << m_name << std::endl;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

std::ostream &operator<<(std::ostream &o, Form const &src)
{
	o << "Form " << src.getName() << " needs grade " << src.getGradeToSign() << " to be signed and grade " << src.getGradeToExecute() << " to be executed and is ";
	if (!src.getIsSigned())
		o << "not ";
	o << "signed";
	return o;
}
