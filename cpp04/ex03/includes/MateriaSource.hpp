#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &cp);

        virtual ~MateriaSource();

        MateriaSource &operator=(MateriaSource const &src);

    protected:
        AMateria *m_inventory[4];

};

#endif 