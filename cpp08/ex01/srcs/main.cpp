#include <iostream>
#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		int arr[] = {6, 3, 17, 9, 11};
		Span sp(5);

		sp.addNumbers(arr, arr + sizeof(arr) / sizeof(arr[0]));
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		Span sp = Span(10000);
		std::vector<int> vec(10000);

		for (int i = 0; i < 10000; i++)
			vec[i] = i;

		sp.addNumbers(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		try
		{
			Span sp = Span(2);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Span sp = Span(1);

			sp.addNumber(6);
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Span sp = Span(3);

			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}
