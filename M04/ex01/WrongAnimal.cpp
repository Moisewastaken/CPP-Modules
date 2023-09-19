#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): _type("Default")
{
	std::cout << this->_type << " default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type): _type(type)
{
	std::cout << this->_type << " name constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &copy)
{
	std::cout << this->_type << " copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << this->_type << " destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const &rhs)
{
	std::cout << this->_type << " overloaded = operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	return *this;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal makeSound function called" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return this->_type;
}