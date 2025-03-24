#pragma once

#include <iostream>
#include <stdint.h>
#include "data.hpp"

class Serializer
{
    public:
        virtual ~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer(const Serializer &cp);
        Serializer &operator=(Serializer const &src);

};