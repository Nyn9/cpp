#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
    public:
        Point();
		Point(const float x, const float y);
        Point(const Point &cp);
        ~Point();
        Point &operator=(Point const &src);
		Fixed getX(void) const;
		Fixed getY(void) const;

    private:
		Fixed const m_x;
		Fixed const m_y;
};

#endif