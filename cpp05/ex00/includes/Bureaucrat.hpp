#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat();
		Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &cp);

        virtual ~Bureaucrat();

        Bureaucrat &operator=(Bureaucrat const &src);

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		std::string GradeTooHighException() const;
		std::string GradeTooLowException() const;

    protected:
		const std::string m_name;
		int	m_grade;
};

#endif