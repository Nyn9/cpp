#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
        WrongAnimal	*unknown = new WrongAnimal();
        std::cout << std::endl;

        const AAnimal *i = new Dog();
        std::cout << std::endl;

        const AAnimal *j = new Cat();
        std::cout << std::endl;

        WrongCat cat;

        std::cout << std::endl << unknown->getType() << std::endl;
        std::cout << i->getType() << std::endl;
        std::cout << j->getType() << std::endl;
        std::cout << cat.getType() << std::endl << std::endl;

        unknown->makeSound();
        i->makeSound();
        j->makeSound();
        cat.makeSound();
        std::cout << std::endl;

        delete unknown;
        std::cout << std::endl;

        unknown = new WrongCat();
        std::cout << unknown->getType() << std::endl;
        unknown->makeSound();
        std::cout << std::endl;

        delete i;
        std::cout << std::endl;

        delete j;
        std::cout << std::endl;

        delete unknown;
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
    Dog basic;
    {
        std::cout << std::endl;
        Dog tmp = basic;
        std::cout << std::endl;
    }
    std::cout << std::endl;

	return 0;
}