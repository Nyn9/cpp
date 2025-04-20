#pragma once

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
    public:
		RPN(std::string str);
        RPN(const RPN &cp);

        virtual ~RPN();

        RPN &operator=(RPN const &src);

		void calculate(std::string str);
		bool checkInput(std::string str);
		int stoi(std::string str);

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DivisionByZeroException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

    private:
        RPN();
		std::stack<int> m_stack;
		std::string m_calc;
};