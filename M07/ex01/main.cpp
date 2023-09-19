#include "Iter.hpp"

int	main(void)
{
	int	intArray[10] = {1, 2 ,3, 4, 5, 6, 7, 8, 9, 10};
	char	charArray[2][4] = {"oui", "non"};

	std::cout << "---Ints---" << std::endl;
	iter(intArray, 10, printElement);
	std::cout << "---Strings---" << std::endl;
	iter(charArray, 2, printElement);
}