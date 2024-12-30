#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	system("clear");
	std::cout << "Welcome to your beautiful phone book ! Please enter a command (ADD, SEARCH, EXIT) : " << std::endl;
	std::getline(std::cin, command);
	while (command.compare("EXIT"))
	{
		if (!command.compare("ADD"))
			phoneBook.addContact();
		else if (!command.compare("SEARCH"))
			phoneBook.searchContact();
		std::cout << "Please enter a command (ADD, SEARCH, EXIT) : " << std::endl;
		std::getline(std::cin, command);
	}
	return 0;
}