#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();

	std::cout << std::endl;

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

	std::cout << std::endl;

    ICharacter* me = new Character("me");

    Character basic;
    {
        Character tmp = basic;
    }

	std::cout << std::endl;

    AMateria* tmp;

	std::cout << std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);

	std::cout << std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);

	std::cout << std::endl;

    ICharacter* bob = new Character("bob");
	bob->equip(tmp);
	me->unequip(1);
	bob->equip(tmp);
	bob->equip(src->createMateria("ice"));
	bob->equip(src->createMateria("Dont exist"));

	std::cout << std::endl;

    me->use(0, *bob);
    me->use(1, *bob);
	bob->use(0, *me);
	bob->use(1, *me);
	bob->use(2, *me);

	me->unequip(0);
	bob->unequip(1);

	std::cout << std::endl;

    delete bob;
    delete me;
    delete src;

    return 0;
}