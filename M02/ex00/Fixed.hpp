#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	fixedValue;
	static const int	fractBits = 8;
public:
	int	getRawBits( void ) const;
	void	setRawBits(int const raw );

	Fixed(void);
	Fixed(const int n);
	Fixed(Fixed const &src);
	~Fixed();

	Fixed	&operator=(Fixed const &rhs);
};



#endif