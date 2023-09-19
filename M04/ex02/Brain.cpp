#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain( Brain const &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain	&Brain::operator=( Brain const &rhs)
{
	std::cout << "Brain overloaded = operator called" << std::endl;
	if (this == &rhs)
		return *this;
	for (int i = 0;i < 100;i++)
		this->_ideas[i] = rhs._ideas[i];
	return *this;
}