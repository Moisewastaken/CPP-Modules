#include "Zombie.hpp"

int	main(void)
{
	size_t	znum;
	Zombie	*horde;

	znum = 50;
	horde = zombieHorde(znum, "Zomb");
	for (size_t i = 0;i < znum;i++)
		horde[i].announce();
	delete []horde;
	return (0);
}