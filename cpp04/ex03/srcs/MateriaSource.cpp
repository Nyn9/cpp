#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor Called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &cp)
{
    std::cout << "MateriaSource copy constructor Called" << std::endl;
    *this = cp;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor Called" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
    std::cout << "MateriaSource assignation operator Called" << std::endl;
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
            m_inventory[i] = src.m_inventory[i];
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
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (m_inventory[i] && m_inventory[i]->getType() == type)
            return m_inventory[i]->clone();
    }
    return NULL;
}