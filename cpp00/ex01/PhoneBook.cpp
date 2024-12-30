#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	m_nbContact = 0;
	m_contactIndex = 0;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	system("clear");
	std::cout << "First Name : ";
	std::getline(std::cin, firstName);
	m_contacts[m_contactIndex].setFirstName(firstName);
	std::cout << "Last Name : ";
	std::getline(std::cin, lastName);
	m_contacts[m_contactIndex].setLastName(lastName);
	std::cout << "Nickmane : ";
	std::getline(std::cin, nickname);
	m_contacts[m_contactIndex].setNickname(nickname);
	std::cout << "Phone Number : ";
	std::getline(std::cin, phoneNumber);
	m_contacts[m_contactIndex].setPhoneNumber(phoneNumber);
	std::cout << "Darkest Secret : ";
	std::getline(std::cin, darkestSecret);
	m_contacts[m_contactIndex].setDarkestSecret(darkestSecret);
	if (m_contactIndex == 8)
		m_contactIndex = 0;
	m_contactIndex++;
	if (m_contactIndex > m_nbContact)
		m_nbContact = m_contactIndex;
	system("clear");
	std::cout << "Contact succesfully added !" << std::endl << std::endl;
}

void printInfo(std::string info)
{
	if (info.length() > 10)
		std::cout << info.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << info << "|";
}

void PhoneBook::searchContact()
{
	std::string	index;
	int			intIndex;
	system("clear");
	if (!m_nbContact)
	{
		std::cout << "Empty phone book. You need to add a contact first." << std::endl << std::endl;
		return ;
	}
	for (int i = 0; i < m_nbContact; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		printInfo(m_contacts[i].getFirstName());
		printInfo(m_contacts[i].getLastName());
		printInfo(m_contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << std::endl << "Select a contact by typing its index number : ";
	std::getline(std::cin, index);
	intIndex = atoi(index.c_str());
	while (intIndex < 1 || intIndex > m_nbContact)
	{
		std::cout << "Please select a correct number : ";
		std::getline(std::cin, index);
		intIndex = atoi(index.c_str());
	}
	system("clear");
	std::cout << "First Name : " << m_contacts[intIndex - 1].getFirstName() << std::endl;
	std::cout << "Last Name : " << m_contacts[intIndex - 1].getLastName() << std::endl;
	std::cout << "Nickname : " << m_contacts[intIndex - 1].getNickname() << std::endl;
	std::cout << "Phone Number : " << m_contacts[intIndex - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << m_contacts[intIndex - 1].getDarkestSecret() << std::endl << std::endl;
}
