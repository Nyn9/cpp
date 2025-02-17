#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : m_name("ClapTrap"), m_hitpoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : m_name(name), m_hitpoints(10), m_energyPoints(10), m_attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cp)
{
    *this = cp;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
	if (this != &src)
	{
		m_name = src.m_name;
		m_hitpoints = src.m_hitpoints;
		m_energyPoints = src.m_energyPoints;
		m_attackDamage = src.m_attackDamage;
	}
	return *this;
}

void ClapTrap::attack(std::string const & target)
{
	if (m_energyPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " is out of energy !" << std::endl;
		return ;
	}
	else if (m_hitpoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " is dead !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage !" << std::endl;
	m_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << m_name << " takes " << amount << " points of damage !" << std::endl;
	m_hitpoints -= amount;
	if (m_hitpoints < 0)
		m_hitpoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (m_energyPoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " is out of energy !" << std::endl;
		return ;
	}
	else if (m_hitpoints == 0)
	{
		std::cout << "ClapTrap " << m_name << " is dead !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << m_name << " is repaired for " << amount << " points of damage !" << std::endl;
	m_hitpoints += amount;
	m_energyPoints--;
}