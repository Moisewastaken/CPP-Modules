#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain( void );
		Brain( Brain const &copy);
		~Brain( void );
		Brain	&operator=(Brain const &rhs);

};

#endif