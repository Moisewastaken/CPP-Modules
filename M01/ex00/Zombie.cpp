#include "Zombie.hpp"

Zombie::Zombie(std::string Name): name(Name)
{
	
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " Died!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}