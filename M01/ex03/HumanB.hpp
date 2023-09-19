#ifndef	HUMANB_HPP
#define	HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string	name;
	Weapon	*_Weapon;

public:
	void	setWeapon( Weapon &newWeapon );
	void	attack();

	HumanB( std::string Name );
	~HumanB();
};

#endif
