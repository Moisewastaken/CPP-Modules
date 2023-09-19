#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice: public AMateria
{
	public:
		Ice( void );
		Ice( std::string const &name );
		Ice( Ice const &copy );
		~Ice( void );
		Ice	&operator=( Ice const &rhs );

		virtual AMateria	*clone( void ) const;
		virtual void		use( ICharacter &target );
};

#endif