#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure constructor Called" << std::endl;
    m_type = "cure";
}

Cure::Cure(const Cure &cp) : AMateria(cp)
{
    std::cout << "Cure copy constructor Called" << std::endl;
    *this = cp;
}

Cure::~Cure()
{
    std::cout << "Cure destructor Called" << std::endl;
}

Cure &Cure::operator=(Cure const &src)
{
    std::cout << "Cure assignation operator Called" << std::endl;
	if (this != &src)
        m_isEquiped = src.m_isEquiped;
    return *this;
}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}