#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &cp)
{
    *this = cp;
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return *this;
}

char *itoa(int value)
{
	static char buffer[12];
	sprintf(buffer, "%d", value);
	return buffer;
}

// ######### CHECK FUNCTIONS ######### //

bool isInt(std::string str)
{
	size_t i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == str.length())
		return true;
	return false;
}

bool isFloat(std::string str)
{
	size_t i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == 'f' && i == str.length() - 1)
			return true;
	}
	return false;
}

bool	isDouble(std::string str)
{
	size_t i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (i == str.length())
			return true;
	}
	return false;
}

// ################################## //

//######## PRINT FUNCTIONS ######## //

void	printChar(char c, int i)
{
	std::cout << "char 	: ";
	if (i < 0 || i > 127)
		std::cout << "impossible" << std::endl;
	else if (i < 32 || i > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << c << std::endl;
}

void printInt (int i, std::string str)
{
	std::cout << "int 	: ";
	if (str.c_str() != itoa(i))
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
}

void printFloat (float f)
{
	std::cout << "float 	: ";
	if (f > FLT_MAX || f < -FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void printDouble (double d)
{
	std::cout << "double 	: ";
	if (d > DBL_MAX || d < -DBL_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

//################################## //

void ScalarConverter::convert(std::string str)
{
	if (str.length() == 1 && !isInt(str))
	{
		std::cout << "char 	: " << str[0] << std::endl;
		std::cout << "int 	: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float 	: " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double 	: " << static_cast<double>(str[0]) << ".0" << std::endl;
	}
	else if(isFloat(str))
	{
		float f = std::atof(str.c_str());
		int i = static_cast<int>(f);
		char c = static_cast<char>(f);
		double d = static_cast<double>(f);
		printChar(c, i);
		printInt(i, str);
		printFloat(f);
		printDouble(d);
	}
	else if(isDouble(str))
	{
		double d = std::atof(str.c_str());
		int i = static_cast<int>(d);
		char c = static_cast<char>(d);
		float f = static_cast<float>(d);
		printChar(c, i);
		printInt(i, str);
		printFloat(f);
		printDouble(d);
	}
	else if (isInt(str))
	{
		int i = std::atoi(str.c_str());
		char c = static_cast<char>(i);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);
		printChar(c, i);
		printInt(i, str);
		printFloat(f);
		printDouble(d);
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char 	: impossible" << std::endl;
		std::cout << "int	: " << INT_MIN << std::endl;
		std::cout << "float	: " << __FLT_MIN__ << std::endl;
		std::cout << "double	: " << __DBL_MIN__ << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char 	: impossible" << std::endl;
		std::cout << "int	: " << INT_MAX << std::endl;
		std::cout << "float	: " << __FLT_MAX__ << std::endl;
		std::cout << "double	: " << __DBL_MAX__ << std::endl;
	}
	else
	{
		std::cout << "char 	: impossible" << std::endl;
		std::cout << "int 	: impossible" << std::endl;
		std::cout << "float 	: nanf" << std::endl;
		std::cout << "double 	: nan" << std::endl;
	}
	
}