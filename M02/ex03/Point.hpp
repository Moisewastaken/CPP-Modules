#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point( void );
		Point( float const x, float const y );
		Point( Point const &copy );
		~Point( void );

		Point	&operator=( Point const &rhs );

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );


#endif