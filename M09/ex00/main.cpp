#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	(void)argc;
	std::string	str;
	BitcoinExchange	btc("data.csv");

	if (argc != 2)
	{
		std::cerr << "Error: wrong number of argument wanted 'something.txt'" << std::endl;
		return 0;
	}
	if (argv[1])
		str = argv[1];
	btc.displayInfo(str);
}