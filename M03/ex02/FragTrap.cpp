#include "FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap()
{
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap( name )
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " : Name constructor called" << std::endl;
}

FragTrap::FragTrap( FragTrap const &copy ): ClapTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap " << this->_name << "  : Copy ClapTrap constructor called" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap " << this->_name << " : Destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=( FragTrap const &rhs)
{
	this->_attackDamage = rhs._attackDamage;
	this->_energyPoints = rhs._energyPoints;
	this->_hitPoints = rhs._hitPoints;
	this->_name = rhs._name;
	std::cout << "FragTrap " << this->_name << "  : Overloaded operator = called" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->_name << " want's to high five !" << std::endl;
}