#include <iostream>
#include <vector>
#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n------------------------\n" << std::endl;

	{
		std::vector<int> v;

		v.push_back(5);
		v.push_back(17);
		std::cout << v.back() << std::endl;
		v.pop_back();
		std::cout << v.size() << std::endl;
		v.push_back(3);
		v.push_back(5);
		v.push_back(737);
		v.push_back(0);

		std::vector<int>::iterator it = v.begin();
		std::vector<int>::iterator ite = v.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
