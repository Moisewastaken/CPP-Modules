#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <list>
#include <algorithm>

template<typename T>
void	easyfind( T &type, int	toFind)
{
	if (std::find(type.begin(), type.end(), toFind) != type.end())
		std::cout << toFind << " found !" << std::endl;
	else
		std::cout << "Can't find " << toFind << std::endl;
}


#endif
