#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	m_type = "Cat";
	m_brain = new Brain();
}

Cat::Cat(const Cat &cp) : Animal(cp)
{
	std::cout << "Cat copy constructor called" << std::endl;
    *this = cp;
}

Cat::~Cat()
{
	delete m_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
    {
        m_brain = new Brain(*src.m_brain); 
		m_type = src.m_type;
    }
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaou !" << std::endl;
}