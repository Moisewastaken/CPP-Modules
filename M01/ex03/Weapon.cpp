#include "Weapon.hpp"

Weapon::Weapon(std::string newType)
{
	this->type = newType;
}

Weapon::~Weapon()
{

}

const std::string	&Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}