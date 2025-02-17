#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->m_name = "FragTrap";
	this->m_hitpoints = 100;
	this->m_energyPoints = 100;
	this->m_attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->m_name = name;
	this->m_hitpoints = 100;
	this->m_energyPoints = 100;
	this->m_attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cp) : ClapTrap(cp)
{
    *this = cp;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << m_name << " is asking for a high five !" << std::endl;
}
