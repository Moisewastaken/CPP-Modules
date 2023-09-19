#include "Span.hpp"

Span::Span( void ): _n(0)
{
	return ;
}

Span::Span( unsigned int n ): _n(n)
{
	return ;
}

Span::Span( Span const &copy)
{
	*this = copy;
}

Span  &Span::operator=( Span const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_n = rhs._n;
	this->_list = std::list<int>(rhs._list);
	return *this;
}

Span::~Span( void )
{
	return ;
}

void	Span::addNumber( int number)
{
	if (_list.size() >= this->_n)
		throw ListFullException();
	this->_list.push_back(number);
}

void	Span::addNumbers( std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_list.size() >= this->_n)
		throw ListFullException();
	this->_list.insert(this->_list.end(), begin, end);
}

int	Span::longestSpan( void )
{
	if (_list.size() < 2)
		throw ListTooShortException();
	return (*std::max_element(this->_list.begin(), this->_list.end()) - *std::min_element(this->_list.begin(), this->_list.end()));
}

int	Span::shortestSpan( void )
{
	if (_list.size() < 2)
		throw ListTooShortException();
	int	shortest = longestSpan();
	std::list<int>	lstTmp = std::list<int>(this->_list);
	lstTmp.sort();
	int	tmp = *lstTmp.begin();
	std::list<int>::iterator it = lstTmp.begin();
	it++;
	while (it != lstTmp.end())
	{
		if (std::abs(*it - tmp) < shortest)
			shortest = std::abs(*it - tmp);
		tmp = *it;
		it++;
	}
	return shortest;
}

const char *Span::ListFullException::what( void ) const throw()
{
	return "Error : list full";
}

const char *Span::ListTooShortException::what( void ) const throw()
{
	return "Error : list too short";
}
