#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(std::string str) : m_calc(str)
{
	if (!checkInput(m_calc))
		throw InvalidInputException();
	calculate(m_calc);
}

RPN::RPN(const RPN &cp)
{
    *this = cp;
}

RPN::~RPN()
{

}

RPN &RPN::operator=(RPN const &src)
{
	if (this != &src)
	{
		this->m_stack = src.m_stack;
		this->m_calc = src.m_calc;
    }
	return *this;
}

void RPN::calculate(std::string str)
{
	int nb1;
	int nb2;

	for (size_t i = 0; i < str.length(); i++)
	{
		nb1 = 0;
		nb2 = 0;
		if (isdigit(str[i]))
			m_stack.push(stoi(str.substr(i, 1)));
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (m_stack.size() < 2)
				throw InvalidInputException();
			nb1 = m_stack.top();
			m_stack.pop();
			nb2 = m_stack.top();
			m_stack.pop();
			if (str[i] == '+')
				m_stack.push(nb1 + nb2);
			else if (str[i] == '-')
				m_stack.push(nb2 - nb1);
			else if (str[i] == '*')
				m_stack.push(nb1 * nb2);
			else if (str[i] == '/')
			{
				if (nb1 == 0)
					throw DivisionByZeroException();
				m_stack.push(nb2 / nb1);
			}
		}
	}
	std::cout << m_stack.top() << std::endl;
}

bool RPN::checkInput(std::string str)
{
	int n;
	int count = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((isdigit(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && str[i + 1] && str[i + 1] != ' ')
			return false;
		if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
			return false;
		if ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && count < 2)
			return false;
		if (isdigit(str[i]))
		{
			n = stoi(str.substr(i, str.find(' ', i) - i));
			if (n < 0 || n > 9)
				return false;
			count++;
		}
	}
	int end = str.length() - 1;
	while (str[end] == ' ')
		end--;
	if (str[end] != '+' && str[end] != '-' && str[end] != '*' && str[end] != '/')
		return false;
	return true;
}

int RPN::stoi(std::string str)
{
	std::stringstream s(str);
	int i;

	if (!(s >> i) || !s.eof())
		return -1;
	return i;
}

const char* RPN::InvalidInputException::what() const throw()
{
	return "Invalid input";
}

const char* RPN::DivisionByZeroException::what() const throw()
{
	return "Division by zero";
}