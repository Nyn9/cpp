#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->m_type = "Dog";
}

Dog::Dog(const Dog &cp) : Animal(cp)
{
	std::cout << "Dog copy constructor called" << std::endl;
    *this = cp;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src)
		m_type = src.m_type;
	return *this;
}