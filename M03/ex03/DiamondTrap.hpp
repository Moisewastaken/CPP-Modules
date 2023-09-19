#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class  DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap( void );
		DiamondTrap( std::string name);
		DiamondTrap( DiamondTrap const &copy);
		~DiamondTrap( void );
		DiamondTrap	&operator=( DiamondTrap const &rhs);

		using	ScavTrap::attack;
		void	whoAmI( void );
		unsigned int	getHitP(void) const;
		unsigned int	getEneP(void) const;
};

#endif