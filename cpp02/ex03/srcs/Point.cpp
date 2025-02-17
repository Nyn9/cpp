#include "Point.hpp"

Point::Point(): m_x(0), m_y(0)
{

}

Point::Point(const float x, const float y): m_x(x), m_y(y)
{

}

Point::Point(const Point &cp) : m_x(cp.getX()), m_y(cp.getY())
{
}

Point::~Point()
{

}

Point &Point::operator=(Point const &src)
{
	(void)src;
	return *this;
}

Fixed Point::getX(void) const
{
	return m_x;
}

Fixed Point::getY(void) const
{
	return m_y;
}