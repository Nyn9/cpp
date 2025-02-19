#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain &cp);

        virtual ~Brain();

        Brain &operator=(Brain const &src);

    protected:
		std::string ideas[100];
};

#endif