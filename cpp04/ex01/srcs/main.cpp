#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *tab[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			tab[i] = new Dog();
		else
			tab[i] = new Cat();
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete tab[i];
		std::cout << std::endl;
	}
	return 0;
}