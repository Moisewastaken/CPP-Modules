#include "WrongCat.hpp"

WrongCat::WrongCat( void ): WrongAnimal("WrongCat")
{
	std::cout << this->_type << " default constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const &copy ): WrongAnimal(copy)
{
	std::cout << this->_type << " copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat( void )
{
	std::cout << this->_type << " destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=( WrongCat const &rhs)
{
	std::cout << this->_type << " overloaded = operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	return *this;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "*Meow*" << std::endl;
}