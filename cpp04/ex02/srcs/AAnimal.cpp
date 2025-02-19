#include "AAnimal.hpp"

AAnimal::AAnimal() : m_type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &cp)
{
	std::cout << "Animal copy constructor called" << std::endl;
    *this = cp;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &src)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &src)
		m_type = src.m_type;
	return *this;
}

void AAnimal::makeSound() const
{

}

std::string AAnimal::getType() const
{
	return m_type;
}