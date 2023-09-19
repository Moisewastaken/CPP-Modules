#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private :
		T	*_array;
		unsigned int	_size;
	public :
		Array( void ): _array( new T()), _size(0) {};
		Array( unsigned int n): _array( new T[n]), _size(n) {};
		Array( Array const &copy )
		{
			this->_array = new T[copy.size()];
			this->_size = copy.size();
			for(unsigned int i = 0;i < copy.size();i++)
				this->_array[i] = copy._array[i];
		};
		~Array( void ){delete []_array;};
		Array	&operator=( Array const &rhs )
		{
			if (*this == rhs)
				return *this;
			delete []_array;
			this->_array = new T[rhs.size()];
			this->_size = rhs.size();
			for(unsigned int i = 0;i < rhs.size();i++)
				this->_array[i] = rhs._array[i];
			return *this;
		};

		unsigned int	size( void ) const {return _size;};
		T	&operator[]( unsigned int i) const
		{
			if (i >= _size)
				throw outOfBoundsExeption();
			return (_array[i]);
		};

		class	outOfBoundsExeption: public std::exception
		{
			virtual const char *what() const throw() {return "Index out of bounds";}
		};
};

#endif
