#include "Fixed.hpp"
#include <cmath>

const int Fixed::m_bits = 8;

Fixed::Fixed() : m_fixed(0)
{
}

Fixed::Fixed(const Fixed &cp)
{
    *this = cp;
}

Fixed::Fixed(const int n)
{
	m_fixed = n << m_bits;
}

Fixed::Fixed(const float f)
{
	m_fixed = roundf(f * (1 << m_bits));
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(Fixed const &src)
{
	if (this != &src)
		m_fixed = src.getRawBits();
	return *this;
}

bool Fixed::operator>(Fixed const &src) const
{
	return (m_fixed > src.getRawBits());
}

bool Fixed::operator<(Fixed const &src) const
{
	return (m_fixed < src.getRawBits());
}

bool Fixed::operator>=(Fixed const &src) const
{
	return (m_fixed >= src.getRawBits());
}

bool Fixed::operator<=(Fixed const &src) const
{
	return (m_fixed <= src.getRawBits());
}

bool Fixed::operator==(Fixed const &src) const
{
	return (m_fixed == src.getRawBits());
}

bool Fixed::operator!=(Fixed const &src) const
{
	return (m_fixed != src.getRawBits());
}

Fixed Fixed::operator+(Fixed const &src) const
{
	return Fixed(toFloat() + src.toFloat());
}

Fixed Fixed::operator-(Fixed const &src) const
{
	return Fixed(toFloat() - src.toFloat());
}

Fixed Fixed::operator*(Fixed const &src) const
{
	return Fixed(toFloat() * src.toFloat());
}

Fixed Fixed::operator/(Fixed const &src) const
{
	return Fixed(toFloat() / src.toFloat());
}

Fixed &Fixed::operator++()
{
	m_fixed++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	m_fixed++;
	return tmp;
}

Fixed &Fixed::operator--()
{
	m_fixed--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	m_fixed--;
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (Fixed&)a;
	return (Fixed&)b;
}

Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (Fixed&)a;
	return (Fixed&)b;
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