#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cstdio>

class ScalarConverter
{
    public:
        virtual ~ScalarConverter();

		static void convert(std::string str);

	private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &cp);
        ScalarConverter &operator=(ScalarConverter const &src);

};

#endif