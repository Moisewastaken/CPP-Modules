#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for(int i = 0;i < 4;i++)
		this->_storage[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const &copy )
{
	*this = copy;
}

MateriaSource  &MateriaSource::operator=( MateriaSource const &rhs )
{
	if (this == &rhs)
		return *this;
	for(int i = 0;i < 4;i++)
		this->_storage[i] = rhs._storage[i];
	return *this;
}

MateriaSource::~MateriaSource( void )
{
	for(int i = 0;i < 4;i++)
		if (this->_storage[i])
			delete this->_storage[i];
}

void	MateriaSource::learnMateria( AMateria *m )
{
	for(int i = 0;i < 4;i++)
		if (!this->_storage[i])
		{
			this->_storage[i] = m;
			return ;
		}
}

AMateria	*MateriaSource::createMateria( std::string const &type )
{
	for(int i = 0;i < 4;i++)
		if (this->_storage[i] && this->_storage[i]->getType() == type)
			return this->_storage[i]->clone();
	return NULL;
}
