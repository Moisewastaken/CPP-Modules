#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ): ClapTrap("Default_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = "Default";
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hitPoints = this->FragTrap::_hitPoints;
	this->_energyPoints = this->ScavTrap::_energyPoints;
	this->_attackDamage = this->FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const &copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap " << this->_name << " copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	std::cout << "DiamondTrap " << this->_name << " overload operator = called" << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "DiamonTrap: " << this->_name << " ClapTrap name: " << this->ClapTrap::_name << std::endl; 
	std::cout << "DImondTrap's hitPoints : " << this->_hitPoints << std::endl;
	std::cout << "DImondTrap's energyPoints : " << this->_energyPoints << std::endl;
}

unsigned int	DiamondTrap::getHitP(void) const
{
	return this->_hitPoints;
}

unsigned int	DiamondTrap::getEneP(void) const
{
	return this->_energyPoints;
}