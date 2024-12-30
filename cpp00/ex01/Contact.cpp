#include "Contact.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

std::string Contact::getFirstName()
{
	return m_firstName;
}

std::string Contact::getLastName()
{
	return m_lastName;
}

std::string Contact::getNickname()
{
	return m_nickname;
}

std::string Contact::getPhoneNumber()
{
	return m_phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return m_darkestSecret;
}

void Contact::setFirstName(std::string firstName)
{
	while (!firstName.length())
	{
		std::cout << "This field cannot be empty. Please make sure to enter a valid first name." << std::endl;
		std::cout << "First Name : ";
		std::getline(std::cin, firstName);
	}
	m_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	while (!lastName.length())
	{
		std::cout << "This field cannot be empty. Please make sure to enter a valid last name." << std::endl;
		std::cout << "Last Name : ";
		std::getline(std::cin, lastName);
	}
	m_lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
	while (!nickname.length())
	{
		std::cout << "This field cannot be empty. Please make sure to enter a valid nickname." << std::endl;
		std::cout << "Nickname : ";
		std::getline(std::cin, nickname);
	}
	m_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	while (!phoneNumber.length())
	{
		std::cout << "This field cannot be empty. Please make sure to enter a valid phone number." << std::endl;
		std::cout << "Phone Number : ";
		std::getline(std::cin, phoneNumber);
	}
	m_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	while (!darkestSecret.length())
	{
		std::cout << "This field cannot be empty. Please make sure to enter a valid darkest secret." << std::endl;
		std::cout << "Darkest Secret : ";
		std::getline(std::cin, darkestSecret);
	}
	m_darkestSecret = darkestSecret;
}
