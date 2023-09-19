#include "Ice.hpp"

Ice::Ice( void ): AMateria("ice")
{
	return ;
}

Ice::Ice( Ice const &copy): AMateria("ice")
{
	*this = copy;
}

Ice  &Ice::operator=( Ice const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	return *this;
}

Ice::~Ice( void )
{
	return ;
}

AMateria	*Ice::clone( void ) const
{
	return new Ice(*this);
}

void	Ice::use( ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
