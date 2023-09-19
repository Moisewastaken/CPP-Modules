#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure: public AMateria
{
	public :
		Cure( void );
		Cure( std::string const &name );
		Cure( Cure const &copy );
		~Cure( void );
		Cure	&operator=( Cure const &rhs );

		virtual AMateria	*clone( void ) const;
		virtual void		use/*va chier moise*/( ICharacter &target );
};

#endif