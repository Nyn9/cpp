#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character();
        Character(std::string name);
        Character(const Character &cp);

        virtual ~Character();

        Character &operator=(Character const &src);

    protected:
        std::string m_name;

};

#endif 