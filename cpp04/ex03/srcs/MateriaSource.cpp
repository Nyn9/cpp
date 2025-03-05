#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &cp)
{
    std::cout << "MateriaSource copy constructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (cp.m_inventory[i])
			m_inventory[i] = cp.m_inventory[i]->clone();
		else
			m_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor Called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (m_inventory[i])
			delete m_inventory[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
    std::cout << "MateriaSource assignation operator Called" << std::endl;
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

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!m_inventory[i])
        {
            m_inventory[i] = m;
            return ;
        }
    }
	std::cout << "Inventory is full." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (m_inventory[i] && m_inventory[i]->getType() == type)
            return m_inventory[i]->clone();
    }
    return 0;
}