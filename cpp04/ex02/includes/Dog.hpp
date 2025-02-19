#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog();
        Dog(const Dog &cp);

        virtual ~Dog();

        Dog &operator=(Dog const &src);

		void makeSound() const;

    protected:
		Brain *m_brain;

};

#endif