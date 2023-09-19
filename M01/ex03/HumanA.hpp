#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon	&_Weapon;

public:
	void	setWeapon(std::string type);
	void	attack();
	HumanA( std::string name, Weapon& weaponType);
	~HumanA();
};

#endif