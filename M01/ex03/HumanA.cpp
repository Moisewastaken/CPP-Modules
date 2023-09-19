#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon& weaponType): name(Name), _Weapon(weaponType)
{

}

HumanA::~HumanA(void)
{

}

void	HumanA::setWeapon( std::string type)
{
	this->_Weapon.setType(type);
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacked with their "
	<< this->_Weapon.getType() << std::endl;
}