#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat constructor called" << std::endl;
	m_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &cp) : WrongAnimal(cp)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
    *this = cp;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &src)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &src)
		m_type = src.m_type;
	return *this;
}