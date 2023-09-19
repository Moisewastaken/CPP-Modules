#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	newHarl;

	if (argc != 2)
	{
		std::cerr << "Wrong usage: <complainingLevel>" << std::endl;
		return (0);
	}
	newHarl.complain(argv[1]);
	return (0);
}