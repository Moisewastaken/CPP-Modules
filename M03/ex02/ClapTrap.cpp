#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " : Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " : Name constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &copy )
{
	*this = copy;
	std::cout << "ClapTrap " << this->_name << " : Copy ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap " << this->_name << " : Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const &rhs)
{
	this->_attackDamage = rhs._attackDamage;
	this->_energyPoints = rhs._energyPoints;
	this->_hitPoints = rhs._hitPoints;
	this->_name = rhs._name;
	std::cout << "ClapTrap " << this->_name << " : Overloaded operator called" << std::endl;
	return (*this);
}

void	ClapTrap::attack( std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead !" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage !" << std::endl;
	this->_energyPoints -= 1;
}

void	ClapTrap::beRepaired( unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead !" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repairs itself with " << amount << " of Hit Points" << std::endl;
	this->_hitPoints += amount;
}

void	ClapTrap::takeDamage( unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead !" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage !" << std::endl;
	this->_hitPoints -= amount;
}
