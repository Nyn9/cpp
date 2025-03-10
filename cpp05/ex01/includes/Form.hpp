#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;
#include "Bureaucrat.hpp"

class Form
{
    public:
        Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &cp);

        virtual ~Form();

        Form &operator=(Form const &src);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat &b);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

    private:
		std::string const m_name;
		bool m_isSigned;
		int const m_gradeToSign;
		int const m_gradeToExecute;

};

std::ostream &operator<<(std::ostream &o, Form const &src);

#endif