#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <climits>
#include <string>
#include <cfloat>

class ScalarConverter
{
	private :
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &copy );
	public :
		~ScalarConverter( void );
		ScalarConverter	&operator=( ScalarConverter const &rhs );

		static void	convert( std::string const &literal);
};

#endif
