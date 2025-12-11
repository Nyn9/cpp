#include "AMateria.hpp"

AMateria::AMateria() : m_type("NULL"), m_isEquiped(false)
{
	std::cout << "Materia constructor Called" << std::endl;
}

AMateria::AMateria(std::string const &type) : m_type(type), m_isEquiped(false)
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
		m_isEquiped = src.m_isEquiped;
	}
    return *this;
}

std::string const &AMateria::getType() const
{
    return m_type;
}

bool AMateria::getIsEquiped() const
{
	return m_isEquiped;
}

void AMateria::setIsEquiped(int isEquiped)
{
	m_isEquiped = isEquiped;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}