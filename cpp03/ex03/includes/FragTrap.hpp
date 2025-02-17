#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
		FragTrap(std::string name);
        FragTrap(const FragTrap &cp);

        ~FragTrap();

		void highFivesGuys(void);
};

#endif