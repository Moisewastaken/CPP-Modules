#include "Cure.hpp"

Cure::Cure( void ): AMateria("cure")
{
	return ;
}

Cure::Cure( Cure const &copy): AMateria("cure")
{
	*this = copy;
}

Cure  &Cure::operator=( Cure const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	return *this;
}

Cure::~Cure( void )
{
	return ;
}

AMateria	*Cure::clone( void ) const
{
	return new Cure(*this);
}

void	Cure::use( ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
