#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public:
        Cat();
        Cat(const Cat &cp);

        virtual ~Cat();

        Cat &operator=(Cat const &src);

		void makeSound() const;

    protected:
		Brain *m_brain;
};

#endif