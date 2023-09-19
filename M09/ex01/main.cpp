#include "RPN.hpp"

int	main(int argc, char **argv)
{
	(void)argc;
	std::string	str;
	RPN	rpn;

	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	str = argv[1];
	rpn.rpnCalculator(str);
}