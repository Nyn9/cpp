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

		virtual void learnMateria(AMateria *materia);
		virtual AMateria* createMateria(std::string const & type);

    protected:
        AMateria *m_inventory[4];

};

#endif 