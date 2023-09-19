#include "Fixed.hpp"

Fixed::Fixed(void): fixedValue(0)
{

}

Fixed::Fixed(const int n): fixedValue(n << fractBits)
{

}

Fixed::Fixed(const float n): fixedValue(roundf(n * (1 << fractBits)))
{

}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed(void)
{

}


int		Fixed::getRawBits(void) const
{
	return (this->fixedValue);
}

void	Fixed::setRawBits( int const raw)
{
	this->fixedValue = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << fractBits));
}

int		Fixed::toInt( void ) const
{
	return (this->getRawBits() >> fractBits);
}

std::ostream	&operator<<( std::ostream &in, Fixed const &n)
{
	in << n.toFloat();
	return (in);
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	if (this == &rhs)
		return (*this);
	this->fixedValue = rhs.getRawBits();
	return (*this);
}



Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return ( Fixed (this->toFloat() + rhs.toFloat()) );
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return ( Fixed (this->toFloat() - rhs.toFloat()) );
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return ( Fixed(this->toFloat() * rhs.toFloat()) );
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return ( Fixed( this->toFloat() / rhs.toFloat()) );
}



Fixed	&Fixed::operator++( void )
{
	this->fixedValue++;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp ( *this );
	tmp.fixedValue = this->fixedValue++;
	return (tmp);
}

Fixed	&Fixed::operator--( void )
{
	this->fixedValue--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp ( *this );
	tmp.fixedValue = this->fixedValue--;
	return (tmp);
}



bool	Fixed::operator==(const Fixed &rhs) const
{
	if (this->fixedValue == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	if (this->fixedValue != rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	if (this->fixedValue <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	if (this->fixedValue >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	if (this->fixedValue < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	if (this->fixedValue > rhs.getRawBits())
		return (true);
	return (false);
}




Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}
