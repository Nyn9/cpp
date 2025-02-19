#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &cp);

        virtual ~WrongAnimal();

        WrongAnimal &operator=(WrongAnimal const &src);

		void makeSound() const;

		std::string getType() const;

    protected:
		std::string m_type;
};

#endif