#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;
#include "Bureaucrat.hpp"

class AForm
{
    public:
        AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &cp);

        virtual ~AForm();

        AForm &operator=(AForm const &src);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor) const;

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

		class FormNotSignedException : public std::exception
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

std::ostream &operator<<(std::ostream &o, AForm const &src);

#endif