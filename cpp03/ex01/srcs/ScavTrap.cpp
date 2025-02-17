#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->m_name = "ScavTrap";
	this->m_hitpoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->m_name = name;
	this->m_hitpoints = 100;
	this->m_energyPoints = 50;
	this->m_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cp) : ClapTrap(cp)
{
    *this = cp;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	if (m_energyPoints == 0)
	{
		std::cout << "ScavTrap " << m_name << " is out of energy !" << std::endl;
		return ;
	}
	else if (m_hitpoints == 0)
	{
		std::cout << "ScavTrap " << m_name << " is dead !" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << m_name << " attacks " << target << ", causing " << m_attackDamage << " points of damage !" << std::endl;
	m_energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << m_name << " has entered in Gate keeper mode" << std::endl;
}
