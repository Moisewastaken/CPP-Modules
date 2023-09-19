#include "Point.hpp"

static Fixed	abs(Fixed const n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static Fixed	getDist(Point const a, Point const b, Point const c)
{
	return (((a.getX() * (b.getY() - c.getY())) +
			(b.getX() * (c.getY() - a.getY())) +
			(c.getX() * (a.getY() - b.getY()))) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	std::cout << b.getX() << std::endl;
	if (abs(getDist(a, b, c)) == (abs(getDist(point, a, b)) +
		abs(getDist(point, b, c)) + abs(getDist(point, c, a))))
		return (true);
	return (false);
}