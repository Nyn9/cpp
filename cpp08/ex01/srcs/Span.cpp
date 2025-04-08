#include "Span.hpp"

Span::Span(unsigned int n) : m_size(n)
{

}

Span::Span(const Span &cp)
{
    *this = cp;
}

Span::~Span()
{

}

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->m_size = src.m_size;
		this->m_span = src.m_span;
    }
	return *this;
}

void Span::addNumber(int n)
{
	if (m_span.size() >= m_size)
		throw FullException();
	m_span.push_back(n);
}

int Span::shortestSpan() const
{
	int dist = m_size;
	if (m_span.size() < 2)
		throw LengthException();
	std::vector<int> tmp = m_span;
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 0; i < tmp.size() - 1; i++)
		if (tmp[i + 1] - tmp[i] < dist)
			dist = tmp[i + 1] - tmp[i];
	return dist;
}

int Span::longestSpan() const
{
	if (m_span.size() < 2)
		throw LengthException();
	int min = *std::min_element(m_span.begin(), m_span.end());
	int max = *std::max_element(m_span.begin(), m_span.end());
	return max - min;
}

const char* Span::FullException::what() const throw()
{
	return "Span is full";
}

const char* Span::LengthException::what() const throw()
{
	return "Not enough elements to find a span";
}