#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <string>
#include <climits>
#include <cstdlib>
#include <iomanip>

class PMergeMe
{
	private :
		
	public :
		PMergeMe( void );
		PMergeMe( PMergeMe const &copy );
		~PMergeMe( void );
		PMergeMe	&operator=( PMergeMe const &rhs );

		void	mergeSort( char **input );
};

#endif
