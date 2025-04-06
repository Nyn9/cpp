#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template< typename T >
typename T::iterator easyfind(T& cont, int i)
{
	typename T::iterator it;

	it = find(cont.begin(), cont.end(), i);
	if (it != cont.end())
		return it;
	else
		throw std::out_of_range("Value not found in container");
}