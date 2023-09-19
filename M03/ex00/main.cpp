#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap ClapTrapNo1("ClapTrapNo1");
	ClapTrap ClapTrapNo2("ClapTrapNo2");
	ClapTrap ClapTrapNo3("ClapTrapNo3");

	ClapTrapNo1.attack("oui");
	ClapTrapNo2.attack("non");
	ClapTrapNo1.takeDamage(150);
	ClapTrapNo1.beRepaired(4);
	ClapTrapNo2.takeDamage(5);
	ClapTrapNo3.takeDamage(1);
	ClapTrapNo2.beRepaired(50);
	ClapTrapNo3.beRepaired(8000);
}