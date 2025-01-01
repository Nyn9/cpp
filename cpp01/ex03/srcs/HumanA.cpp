#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : m_name(name), m_weapon(weapon)
{

}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}