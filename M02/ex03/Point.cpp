#include "Point.hpp"

Point::Point( void ): _x(0.0f), _y(0.0f)
{

}

Point::Point( float const x, float const y): _x(x), _y(y)
{

}

Point::Point( Point const &copy ): _x(copy._x), _y(copy._y)
{

}

Point::~Point( void )
{

}

Point	&Point::operator=( Point const &rhs)
{
	if (this == &rhs)
		return (*this);
	(Fixed) this->_y = rhs.getY();
	(Fixed) this->_x = rhs.getX();
	return (*this);
}

Fixed	Point::getX( void ) const
{
	return (this->_x);
}

Fixed	Point::getY( void ) const
{
	return (this->_y);
}
