#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : m_type("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cp)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = cp;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &src)
		m_type = src.m_type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Something wrong happened..." << std::endl;
}

std::string WrongAnimal::getType() const
{
	return m_type;
}