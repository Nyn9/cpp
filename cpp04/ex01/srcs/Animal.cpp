#include "Animal.hpp"

Animal::Animal() : m_type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &cp)
{
	std::cout << "Animal copy constructor called" << std::endl;
    *this = cp;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &src)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &src)
		m_type = src.m_type;
	return *this;
}

void Animal::makeSound() const
{
	if (m_type == "Dog")
		std::cout << "Wouf wouf" << std::endl;
	else if (m_type == "Cat")
		std::cout << "Miaou" << std::endl;
	else
		std::cout << "No sound available" << std::endl;
}

std::string Animal::getType() const
{
	return m_type;
}