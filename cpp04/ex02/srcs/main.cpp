#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	WrongAnimal	*unknown = new WrongAnimal();
	std::cout << std::endl;

	Dog	*dog = new Dog();
	std::cout << std::endl;

	const AAnimal *i = new Dog();
	std::cout << std::endl;

	Cat	cat;

	std::cout << std::endl << unknown->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << cat.getType() << std::endl << std::endl;

	unknown->makeSound();
	dog->makeSound();
	i->makeSound();
	cat.makeSound();
	std::cout << std::endl;

	delete unknown;
	std::cout << std::endl;

	unknown = new WrongCat();
	unknown->makeSound();
	std::cout << std::endl;

	delete dog;
	std::cout << std::endl;

	delete i;
	std::cout << std::endl;

	delete unknown;
	std::cout << std::endl;

	return 0;
}