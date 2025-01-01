#include "Weapon.hpp"

Weapon::Weapon(std::string type): m_type(type)
{

}

Weapon::~Weapon()
{

}

std::string &Weapon::getType()
{
	return m_type;
}

void Weapon::setType(std::string type)
{
	m_type = type;
}