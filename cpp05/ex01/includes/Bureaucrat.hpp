#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;
#include "Form.hpp"

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
		void signForm(class Form &f);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

    protected:
		const std::string m_name;
		int	m_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif