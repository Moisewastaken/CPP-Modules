#include "Dog.hpp"

Dog::Dog( void ): Animal("Dog")
{
	std::cout << this->_type << " default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog( Dog const &copy): Animal(copy)
{
	std::cout << this->_type << " copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog( void )
{
	std::cout << this->_type << " destructor called" << std::endl;
	delete this->_brain;
}

Dog	&Dog::operator=( Dog const &rhs)
{
	std::cout << this->_type << " overloaded = operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	this->_brain = new Brain( *rhs._brain);
	return *this;
}

void	Dog::makeSound( void ) const
{
	std::cout << "+Woo+" << std::endl;
}