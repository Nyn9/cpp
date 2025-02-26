#include "Character.hpp"

Character::Character()
{
    std::cout << "Character constructor Called" << std::endl;
}

Character::Character(std::string name) : m_name(name)
{
    std::cout << "Character constructor Called" << std::endl;
}

Character::Character(const Character &cp)
{
    std::cout << "Character copy constructor Called" << std::endl;
    *this = cp;
}

Character::~Character()
{
    std::cout << "Character destructor Called" << std::endl;
}

Character &Character::operator=(Character const &src)
{
    std::cout << "Character assignation operator Called" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
            m_inventory[i] = src.m_inventory[i];
    }
    return *this;
}

std::string const &Character::getName() const
{
    return m_name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!m_inventory[i])
        {
            m_inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        m_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && m_inventory[idx])
        m_inventory[idx]->use(target);
}

