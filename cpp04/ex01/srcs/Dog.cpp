#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	m_type = "Dog";
	m_brain = new Brain();
}

Dog::Dog(const Dog &cp) : Animal(cp)
{
	std::cout << "Dog copy constructor called" << std::endl;
    *this = cp;
}

Dog::~Dog()
{
	delete m_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src)
    {
        m_brain = new Brain(*src.m_brain);
		m_type = src.m_type;
    }
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Wouf !" << std::endl;
}