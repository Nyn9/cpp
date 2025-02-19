#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const Cat &cp);
        virtual ~Cat();
        Cat &operator=(Cat const &src);

    protected:
		Brain *m_brain;
};

#endif