#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed & cp);
		Fixed(const int n);
		Fixed(const float f);
        ~Fixed();
        Fixed &operator=(Fixed const &src);
		bool operator>(Fixed const &src) const;
		bool operator<(Fixed const &src) const;
		bool operator>=(Fixed const &src) const;
		bool operator<=(Fixed const &src) const;
		bool operator==(Fixed const &src) const;
		bool operator!=(Fixed const &src) const;
		Fixed operator+(Fixed const &src) const;
		Fixed operator-(Fixed const &src) const;
		Fixed operator*(Fixed const &src) const;
		Fixed operator/(Fixed const &src) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed const &a, Fixed const &b);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

    private:
		static const int	m_bits;
		int					m_fixed;
};

std::ostream &operator<<(std::ostream &o, Fixed const &src);

#endif