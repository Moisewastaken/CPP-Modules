#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Only one argument will be accepted" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
}