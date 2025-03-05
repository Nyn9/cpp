#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Default"), m_grade(150)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name), m_grade(grade)
{
	if (m_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (m_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &cp)
{
    *this = cp;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
	{
		m_name = src.m_name;
		m_grade = src.m_grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const
{
	return m_name;
}

int Bureaucrat::getGrade() const
{
	return m_grade;
}

void Bureaucrat::incrementGrade()
{
	if (m_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	m_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (m_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	m_grade++;
}

std::string Bureaucrat::GradeTooHighException() const
{
	return "Grade too high";
}

std::string Bureaucrat::GradeTooLowException() const
{
	return "Grade too low";
}