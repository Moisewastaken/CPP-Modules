#include "AMateria.hpp"

AMateria::AMateria( void ): _type("Default")
{
	return ;
}

AMateria::AMateria( std::string const &type ): _type(type)
{
	return ;
}

AMateria::AMateria( AMateria const &copy)
{
	*this = copy;
}

AMateria  &AMateria::operator=( AMateria const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_type = rhs._type;
	return *this;
}

AMateria::~AMateria( void )
{
	return ;
}

std::string	const	&AMateria::getType( void ) const
{
	return this->_type;
}

AMateria	*AMateria::clone( void ) const
{
	return (AMateria *)this;
}

void	AMateria::use( ICharacter &target)
{
	std::cout << "AMateria " << this->_type << "used on " << target.getName() << std::endl;
}