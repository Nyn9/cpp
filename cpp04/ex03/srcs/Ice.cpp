#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructor Called" << std::endl;
    m_type = "ice";
}

Ice::Ice(const Ice &cp) : AMateria(cp)
{
    std::cout << "Ice copy constructor Called" << std::endl;
    *this = cp;
}

Ice::~Ice()
{
    std::cout << "Ice destructor Called" << std::endl;
}

Ice &Ice::operator=(Ice const &src)
{
    std::cout << "Ice assignation operator Called" << std::endl;
    return *this;
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}