#include <iostream>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(NULL));
	int r = rand();
	if (r % 3 == 0)
		return new A;
	else if (r % 3 == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (...) {}

	try
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (...) {}

	try
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (...) {}
}


int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}