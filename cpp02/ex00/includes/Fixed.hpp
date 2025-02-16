#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed & cp);
        ~Fixed();
        Fixed &operator=(Fixed const &src);
		int getRawBits(void) const;
		void setRawBits(int const raw);

    private:
		static const int	m_bits;
		int					m_fixed;
};

#endif