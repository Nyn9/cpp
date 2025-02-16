#include "Fixed.hpp"
#include <cmath>

const int Fixed::m_bits = 8;

Fixed::Fixed() : m_fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cp)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = cp;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	m_fixed = n << m_bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	m_fixed = roundf(f * (1 << m_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		m_fixed = src.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const
{
	return m_fixed;
}

void Fixed::setRawBits( int const raw )
{
	m_fixed = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)m_fixed / (1 << m_bits));
}

int Fixed::toInt( void ) const
{
	return m_fixed >> m_bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &src)
{
	o << src.toFloat();
	return o;
}