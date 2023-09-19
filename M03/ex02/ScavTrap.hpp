#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:

	public:
		ScavTrap( void );
		ScavTrap( std::string name);
		ScavTrap( ScavTrap const &copy);
		~ScavTrap( void );
		ScavTrap	&operator=( ScavTrap const &rhs);

		void	attack( const std::string& target );
		void	guardGate( void );
};

#endif