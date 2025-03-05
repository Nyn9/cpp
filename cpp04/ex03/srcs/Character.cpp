#include "Character.hpp"

std::vector<AMateria*> Character::m_trash;

Character::Character() : m_name("NULL")
{
    std::cout << "Character constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::Character(std::string name) : m_name(name)
{
    std::cout << "Character constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

Character::Character(const Character &cp) : m_name(cp.m_name)
{
    std::cout << "Character copy constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (cp.m_inventory[i])
			m_inventory[i] = cp.m_inventory[i]->clone();
		else
			m_inventory[i] = NULL;
	}
}

Character::~Character()
{
    std::cout << "Character destructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (m_inventory[i])
			delete m_inventory[i];
	for (size_t i = 0; i < m_trash.size(); i++)
	{
		if (m_trash[i] && !m_trash[i]->getIsEquiped())
			delete m_trash[i];
	}
	m_trash.clear();
}

Character &Character::operator=(Character const &src)
{
    std::cout << "Character assignation operator Called" << std::endl;
    if (this != &src)
    {
		for (int i = 0; i < 4; i++)
			if (m_inventory[i])
				delete m_inventory[i];
        for (int i = 0; i < 4; i++)
		{
			if (src.m_inventory[i])
				m_inventory[i] = src.m_inventory[i]->clone();
			else
				m_inventory[i] = NULL;
		}
    }
    return *this;
}

std::string const &Character::getName() const
{
    return m_name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	if (m->getIsEquiped())
	{
		std::cout << "Materia already equiped by an other character." << std::endl;
		return ;
	}
    for (int i = 0; i < 4; i++)
    {
        if (!m_inventory[i])
        {
			m->setIsEquiped(1);
            m_inventory[i] = m;

			for (size_t j = 0; j < m_trash.size(); j++)
				if (m_trash[j] == m)
					m_trash.erase(m_trash.begin() + j);
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
	{
		m_inventory[idx]->setIsEquiped(0);
		m_trash.push_back(m_inventory[idx]);
        m_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && m_inventory[idx])
        m_inventory[idx]->use(target);
}

