#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal( void );
		Animal( std::string type );
		Animal( Animal const &copy );
		virtual ~Animal( void );
		Animal	&operator=( Animal const &rhs);

		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;
};

#endif