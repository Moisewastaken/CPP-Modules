#include "HumanB.hpp"

HumanB::HumanB(std::string Name): name(Name), _Weapon(NULL)
{

}

HumanB::~HumanB(void)
{

}

void	HumanB::setWeapon( Weapon& newWeapon)
{
	this->_Weapon = &newWeapon;
}

void	HumanB::attack(void)
{
	if (this->_Weapon)
	{
		std::cout << this->name << " attacked with their "
		<< this->_Weapon->getType() << std::endl;
	}
	else
		std::cout << "Can't attack, no weapon" << std::endl;
}