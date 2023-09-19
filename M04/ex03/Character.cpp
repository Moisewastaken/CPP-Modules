#include "Character.hpp"

Character::Character( void ): _name("Default")
{
	for(int i = 0; i < 4;i++)
		this->_materias[i] = NULL;
	return ;
}

Character::Character( std::string const &name): _name(name)
{
	for(int i = 0; i < 4;i++)
		this->_materias[i] = NULL;
	return ;
}

Character::Character( Character const &copy)
{
	*this = copy;
}

Character  &Character::operator=( Character const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_name = rhs._name;
	for(int i = 0;i < 4;i++)
		this->_materias[i] = rhs._materias[i];
	return *this;
}

Character::~Character( void )
{
	for(int i = 0;i < 4;i++)
		if (this->_materias[i])
			delete this->_materias[i];
	return ;
}

std::string	const	&Character::getName( void ) const
{
	return this->_name;
}

void	Character::equip( AMateria *m)
{
	for(int i = 0;i < 4;i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m;
			// std::cout << "Character " << this->_name << " equipped " << m->getType() << std::endl;
			return ;
		}
	}
	// std::cout << "Character " << this->_name << " can't equip" << std::endl;
}

void	Character::unequip( int idx )
{
	if (this->_materias[idx])
	{
		this->_materias[idx] = NULL;
		// std::cout << "Character " << this->_name << " unequipped" << std::endl;
	}
	// else
		// std::cout << "Character " << this->_name << " can't unequip" << std::endl;
}

void	Character::use( int idx, ICharacter &target)
{
	if (this->_materias[idx])
		this->_materias[idx]->use(target);
	else
		std::cout << "Character " << this->_name << " can't use Materia" << std::endl;
}
