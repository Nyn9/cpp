#include "Weapon.hpp"

Weapon::Weapon(std::string type): m_type(type)
{

}

Weapon::~Weapon()
{

}

const std::string &Weapon::getType() const
{
	return m_type;
}

void Weapon::setType(std::string type)
{
	m_type = type;
}