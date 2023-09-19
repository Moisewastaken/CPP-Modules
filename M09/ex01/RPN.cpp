#include "RPN.hpp"

RPN::RPN( void )
{
	return ;
}

RPN::RPN( RPN const &copy)
{
	*this = copy;
}

RPN  &RPN::operator=( RPN const &rhs)
{
	(void)rhs;
	return *this;
}

RPN::~RPN( void )
{
	return ;
}

void	RPN::rpnCalculator( const std::string &input )
{
	std::istringstream	iss(input);
	std::stack<int>	stack;
	int	n1, n2;


	for(std::string s;iss >> s;)
	{
		if (s.length() != 1 || (!std::isdigit(s[0]) && !std::strchr("+-*/", s[0])))
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
		if (std::isdigit(s[0]))
		{
			stack.push(s[0] - '0');
			continue;
		}
		if (stack.size() < 2)
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
		n1 = stack.top();
		stack.pop();
		n2 = stack.top();
		stack.pop();
		switch (s[0])
		{
			case '+' :
				stack.push(n2 + n1);
				break ;
			case '-' :
				stack.push(n2 - n1);
				break ;
			case '/' :
				if (n2 == 0 || n1 == 0)
				{
					std::cerr << "Error" << std::endl;
					return ;
				}
				stack.push(n2 / n1);
				break ;
			case '*' :
				stack.push(n2 * n1);
				break ;
			default :
				std::cerr << "Error" << std::endl;
				break ;
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	std::cout << stack.top() << std::endl;
}
