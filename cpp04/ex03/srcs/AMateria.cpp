#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "Materia constructor Called" << std::endl;
}

AMateria::AMateria(const AMateria &cp)
{
    std::cout << "Materia copy constructor Called" << std::endl;
    *this = cp;
}

AMateria::~AMateria()
{
    std::cout << "Materia destructor Called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &src)
{
    std::cout << "Materia assignation operator Called" << std::endl;
    if (this != &src)
    {
        m_type = src.m_type;
    }
    return *this;
}

std::string const &AMateria::getType() const
{
    return m_type;
}