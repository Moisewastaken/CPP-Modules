#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *array, int arrLen, void (*f)(T &))
{
	for(int i = 0;i < arrLen;i++)
		f(array[i]);
}

template<typename T>
void	printElement(T &element)
{
	std::cout << element << std::endl;
}

#endif
