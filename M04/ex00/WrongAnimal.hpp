#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( WrongAnimal const &copy );
		virtual ~WrongAnimal( void );
		WrongAnimal	&operator=( WrongAnimal const &rhs);

		void	makeSound( void ) const;
		std::string		getType( void ) const;
};

#endif