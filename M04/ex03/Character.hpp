#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include <iostream>

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_materias[4];
	public :
		Character( void );
		Character( std::string const &name );
		Character( Character const &copy );
		~Character( void );
		Character	&operator=( Character const &rhs );

		std::string const &getName( void ) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};

#endif