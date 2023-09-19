#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): ClapTrap()
{
	std::cout << "ScavTrap " << this->_name << " : Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap( name )
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " : Name constructor called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &copy ): ClapTrap(copy)
{
	*this = copy;
	std::cout << "ScavTrap " << this->_name << " : Copy ClapTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap " << this->_name << " : Destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const &rhs)
{
	this->_attackDamage = rhs._attackDamage;
	this->_energyPoints = rhs._energyPoints;
	this->_hitPoints = rhs._hitPoints;
	this->_name = rhs._name;
	std::cout << "ScavTrap " << this->_name << " : Overloaded operator = called" << std::endl;
	return (*this);
}

void	ScavTrap::attack( std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead !" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy !" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage !" << std::endl;
	this->_energyPoints -= 1;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode" << std::endl;
}