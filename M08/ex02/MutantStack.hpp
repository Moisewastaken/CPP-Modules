#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template<typename T>
class MutantStack: public std::stack<T>
{

	public :
		MutantStack( void ){};
		MutantStack( MutantStack const &copy )
		{
			*this = copy;
		};
		~MutantStack( void ){};
		MutantStack	&operator=( MutantStack const &rhs )
		{
			if (*this == rhs)
				return *this;
			this->std::stack<T>::operator=(rhs);
			return *this;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin( void )
		{
			return this->c.begin();
		}

		iterator	end( void )
		{
			return	this->c.end();
		}
};

#endif
