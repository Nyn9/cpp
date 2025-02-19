#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
    public:
        AAnimal();
        AAnimal(const AAnimal &cp);
        virtual ~AAnimal();

        AAnimal &operator=(AAnimal const &src);

		virtual void makeSound() const = 0;

		std::string getType() const;

    protected:

		std::string m_type;
};

#endif