#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap ClapTrap1("ClapTrap");
	ScavTrap ScavTrap1("ScavTrap");
	FragTrap FragTrap1("FragTrap");

	ClapTrap1.attack("oui");
	ClapTrap1.attack("non");
	ClapTrap1.takeDamage(150);
	ClapTrap1.beRepaired(4);
	ScavTrap1.takeDamage(5);
	FragTrap1.takeDamage(1);
	ScavTrap1.beRepaired(50);
	FragTrap1.beRepaired(8000);
	ScavTrap1.guardGate();
	FragTrap1.highFivesGuys();
	FragTrap1.attack("lesgo");
}