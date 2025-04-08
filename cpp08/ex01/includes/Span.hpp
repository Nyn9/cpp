#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    public:
		Span(unsigned int n);
        Span(const Span &cp);

        virtual ~Span();

        Span &operator=(Span const &src);

		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename It>
		void addNumbers(It begin, It end)
		{
			while(begin != end)
			{
				addNumber(*begin);
				begin++;
			}
		}

		class FullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class LengthException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

    private:
        Span();
		unsigned int m_size;
		std::vector<int> m_span;

};