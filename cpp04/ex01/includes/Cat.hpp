#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &cp);

        virtual ~Cat();

        Cat &operator=(Cat const &src);

        void makeSound() const;

    private:
		Brain *m_brain;
};

#endif