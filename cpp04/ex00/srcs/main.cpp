#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	WrongAnimal	*unknown = new WrongAnimal();
	Dog	*dog = new Dog();
	Cat	cat;

	std::cout << std::endl << unknown->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat.getType() << " " << std::endl << std::endl;

	unknown->makeSound();
	dog->makeSound();
	cat.makeSound();

	std::cout << std::endl;

	delete unknown;
	unknown = new WrongCat();
	unknown->makeSound();

	std::cout << std::endl;

	delete dog;
	delete unknown;
}