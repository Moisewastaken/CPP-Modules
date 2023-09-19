#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct	Data
{
	int	i;
};

class Serializer
{
	private :
		Serializer( void );
		Serializer( Serializer const &copy );
	public :

		~Serializer( void );
		Serializer	&operator=( Serializer const &rhs );

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
