#include "Fixed.hpp"

Fixed::Fixed(void): fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n): fixedValue(n << fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n): fixedValue(roundf(n * (1 << fractBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	this->fixedValue = rhs.getRawBits();
	return (*this);
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
