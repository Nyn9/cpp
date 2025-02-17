#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	ClapTrap::m_name = "DiamondTrap_clap_name";
	this->m_name = "DiamondTrap";
	this->m_hitpoints = FragTrap::m_hitpoints;
	this->m_energyPoints = ScavTrap::m_energyPoints;
	this->m_attackDamage = FragTrap::m_attackDamage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	ClapTrap::m_name = name + "_clap_name";
	this->m_name = name;
	this->m_hitpoints = FragTrap::m_hitpoints;
	this->m_energyPoints = ScavTrap::m_energyPoints;
	this->m_attackDamage = FragTrap::m_attackDamage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cp) : ClapTrap(cp), ScavTrap(cp), FragTrap(cp)
{
    *this = cp;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->m_name << " and my ClapTrap name is " << ClapTrap::m_name << std::endl;
}