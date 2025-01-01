#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include <iostream>
#include "Weapon.hpp"


class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
		void attack();

    private:
		std::string	m_name;
		Weapon		&m_weapon;
};

#endif