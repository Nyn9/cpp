#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->m_type = "Dog";
	m_brain = new Brain();
}

Dog::Dog(const Dog &cp) : AAnimal(cp)
{
	std::cout << "Dog copy constructor called" << std::endl;
    *this = cp;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete m_brain;
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src)
		m_type = src.m_type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Wouf wouf" << std::endl;
}