#ifndef HUMANB_H
#define HUMANB_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);

    private:
		std::string	m_name;
		Weapon		*m_weapon;
};

#endif