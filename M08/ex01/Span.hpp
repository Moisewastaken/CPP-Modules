#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>
#include <climits>
#include <vector>
#include <algorithm>

class Span
{
	private :
		std::list<int>	_list;
		unsigned int	_n;
	public :
		Span( void );
		Span( unsigned int _n);
		Span( Span const &copy );
		~Span( void );
		Span	&operator=( Span const &rhs );

		void	addNumber( int number );
		void	addNumbers( std::vector<int>::iterator begin, std::vector<int>::iterator end );
		int		shortestSpan( void );
		int		longestSpan( void );

		class	ListFullException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class	ListTooShortException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif
