#include "Animal.hpp"

Animal::Animal( void ): _type("Default")
{
	std::cout << this->_type << " default constructor called" << std::endl;
}

Animal::Animal( std::string type): _type(type)
{
	std::cout << this->_type << " name constructor called" << std::endl;
}

Animal::Animal( Animal const &copy)
{
	std::cout << this->_type << " copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal( void )
{
	std::cout << this->_type << " destructor called" << std::endl;
}

Animal	&Animal::operator=( Animal const &rhs)
{
	std::cout << this->_type << " overloaded = operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	return *this;
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animal makeSound function called" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return this->_type;
}