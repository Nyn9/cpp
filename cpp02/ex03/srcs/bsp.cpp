#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if ((c.getX() - point.getX()) * (a.getY() - point.getY()) - (c.getY() - point.getY()) * (a.getX() - point.getX()) >= 0 &&
		(a.getX() - point.getX()) * (b.getY() - point.getY()) - (a.getY() - point.getY()) * (b.getX() - point.getX()) >= 0 &&
		(b.getX() - point.getX()) * (c.getY() - point.getY()) - (b.getY() - point.getY()) * (c.getX() - point.getX()) >= 0)
		return true;
	return false;
}