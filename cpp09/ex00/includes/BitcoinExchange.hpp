#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>
#include <ctime>
#include <sstream>
#include <utility>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string file);
		BitcoinExchange(std::string file, std::string db_path);
		BitcoinExchange(const BitcoinExchange &cp);

		~BitcoinExchange();

		BitcoinExchange	&operator =(const BitcoinExchange &src);

		std::string getFile() const;

		void parseDB();
		void parseArg(std::string arg);
		bool checkDate(std::string str);
		bool checkValue(std::string str, bool err);
		float getRate(std::string date);
		float stof(std::string str);

	private:
		BitcoinExchange();
		std::string m_file;
		std::map<std::string, float> m_data;
};