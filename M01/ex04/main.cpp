#include <iostream>
#include "Sed2.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: wrong usage : <filename> <toFind> <toReplace>" << std::endl;
		return (0);
	}
	Sed2 sed(argv[1]);
	sed.replace(argv[2], argv[3]);
	return (0);
}