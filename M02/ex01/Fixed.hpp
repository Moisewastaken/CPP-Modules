#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					fixedValue;
	static const int	fractBits = 8;
public:
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	Fixed( void );
	Fixed( const int n );
	Fixed( const float n );
	Fixed( Fixed const &src );
	~Fixed();

	Fixed	&operator=(Fixed const &rhs);
};

std::ostream	&operator<<( std::ostream &in, Fixed const &n);

#endif