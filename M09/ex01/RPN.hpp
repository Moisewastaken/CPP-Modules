#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <sstream>

class RPN
{
	public :
		RPN( void );
		RPN( RPN const &copy );
		~RPN( void );
		RPN	&operator=( RPN const &rhs );

		void	rpnCalculator( const std::string &input);
};

#endif
