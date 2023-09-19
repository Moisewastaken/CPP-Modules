#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_storage[4];
	public :
		MateriaSource( void );
		MateriaSource( MateriaSource const &copy );
		~MateriaSource( void );
		MateriaSource	&operator=( MateriaSource const &rhs );

		void	learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

#endif