#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac > 2)
			std::cerr << "Error: too many arguments." << std::endl;
		else
			std::cerr << "Error: could not open m_file." << std::endl;
		return (1);
	}
	BitcoinExchange btc = BitcoinExchange(av[1], "data.csv");
}
