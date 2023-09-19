#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap ClapTrap1("ClapTrap");
	ScavTrap ScavTrap1("ScavTrap1");
	ScavTrap ScavTrap2("ScavTrap2");
	ScavTrap copy(ScavTrap1);

	ClapTrap1.attack("oui");
	ClapTrap1.attack("non");
	copy.attack("jsp");
	ClapTrap1.takeDamage(150);
	ClapTrap1.beRepaired(4);
	ScavTrap1.takeDamage(5);
	ScavTrap2.takeDamage(1);
	ScavTrap1.beRepaired(50);
	ScavTrap2.beRepaired(8000);
	ScavTrap2.guardGate();
	ScavTrap2.attack("lesgo");
}