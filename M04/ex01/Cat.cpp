#include "Cat.hpp"

Cat::Cat( void ): Animal("Cat")
{
	std::cout << this->_type << " default constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat( Cat const &copy ): Animal(copy)
{
	std::cout << this->_type << " copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat( void )
{
	std::cout << this->_type << " destructor called" << std::endl;
	delete	this->_brain;
}

Cat	&Cat::operator=( Cat const &rhs)
{
	std::cout << this->_type << " overloaded = operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	this->_brain = new Brain( *rhs._brain);
	return *this;
}

void	Cat::makeSound( void ) const
{
	std::cout << "*Meow*" << std::endl;
}