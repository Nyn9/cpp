#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file)
	: m_file("data.csv")
{
	parseDB();
	parseArg(file);
}

BitcoinExchange::BitcoinExchange(std::string file, std::string db_path)
	: m_file(db_path)
{
	parseDB();
	parseArg(file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	m_file = src.m_file;
	std::map<std::string, float>::iterator it;
	for (it = m_data.begin(); it != m_data.end(); ++it) {
		m_data[it->first] = it->second;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

std::string BitcoinExchange::getFile() const
{
	return m_file;
}

void BitcoinExchange::parseDB()
{
	bool err;
	char *ptr;
	std::string line;
	std::ifstream fileDB(m_file.c_str());
	if (!fileDB.is_open())
	{
		std::cerr << "Error: could not open database m_file" << std::endl;
		exit(1);
	}

	m_data.clear();
	while (getline(fileDB,line))
	{
		if (line == "date,exchange_rate")
			continue;
		err = false;
		ptr = strtok((char *)line.c_str(), ",");
		std::string date;
		std::string value;
		while (ptr)
		{
			if (date.empty())
				date = ptr;
			else if (value.empty())
				value = ptr;
			else
				err = true;
			ptr = strtok(NULL, ",");
		}
		if (!checkDate(date) && !err)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			err = true;
		}
		if (!checkValue(value, err) && !err)
			err = true;
		if (!err)
			this->m_data[date] = stof(value);
	}
	fileDB.close();
}

void BitcoinExchange::parseArg(std::string av)
{
	char *ptr;
	bool err;
	std::string line;
	std::ifstream inputfile(av.c_str());
	if (!inputfile.is_open())
	{
		std::cerr << "Error: could not open m_file (" << av << ")" << std::endl;
		return ;
	}

	while (getline(inputfile,line))
	{
		if (line == "date | value")
			continue;
		err = false;
		ptr = std::strtok((char *)line.c_str(), " | ");
		std::string date;
		std::string value;
		while (ptr)
		{
			if (date.empty())
				date = ptr;
			else if (value.empty())
				value = ptr;
			else
				err = true;
			ptr = strtok (NULL, " | ");
		}
		if (!checkDate(date) && !err)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			err = true;
		}
		if (!checkValue(value, err) && !err)
			err = true;
		if (!err && stof(value) > 1000)
		{
			std::cerr << "Error: Too large a number." << std::endl;
			err = true;
		}
		if (!err)
		{
			float result = stof(value) * getRate(date);
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
	}
	inputfile.close();
}

float BitcoinExchange::getRate(std::string date)
{
	int comp;
	if (m_data.size() == 0)
		return 0;
	if (m_data.find(date) == m_data.end())
	{
		std::map<std::string, float>::iterator it;
		std::string best_date;
		for (it = m_data.begin(); it != m_data.end(); ++it)
		{
			comp = date.compare(it->first);
			if (comp == -1)
			{
				if (it != m_data.begin())
					it--;
				best_date = it->first;
				break;
			}
		}
		if (best_date.empty())
		{
			it--;
			best_date = it->first;
		}
		return this->m_data[best_date];
	}
	return this->m_data[date];
}

bool BitcoinExchange::checkDate(std::string str)
{
	std::string test_length = str;
	char *ptr;
	ptr = strtok((char *)test_length.c_str(), "-");
	int count = 0;

	while (ptr)
	{
		if (!count && strlen(ptr) != 4)
			return false;
		else if (count && strlen(ptr) != 2)
			return false;
		ptr = strtok(NULL, "-");
		count++;
	}
	if (count != 3)
		return false;
	struct tm result;
	if(strptime(str.c_str(), "%Y-%m-%d", &result) == NULL)
		return false;
	return true;
}

bool BitcoinExchange::checkValue(std::string str, bool err)
{
	std::stringstream s(str);
	float f;

	if (!(s >> f) || !s.eof())
	{
		if (!err)
			std::cerr << "Error: bad input => " << str << std::endl;
		return false;
	}
	if (f < 0)
	{
		if (!err)
			std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	return true;
}

float BitcoinExchange::stof(std::string str)
{
	std::stringstream s(str);
	float f;

	if (!(s >> f) || !s.eof())
		return -1;
	return f;
}