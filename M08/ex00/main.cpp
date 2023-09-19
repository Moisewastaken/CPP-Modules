#include "easyFind.hpp"

int	main(void)
{
	std::list<int>	lst;

	lst.push_back(42);
	lst.push_back(24);
	lst.push_back(21);
	lst.push_back(84);

	easyfind(lst, 21);
	easyfind(lst, 654987);
}