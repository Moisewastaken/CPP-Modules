#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int main( void )
{
	// const Animal*	j = new Dog();
	// const Animal*	i = new Cat();

	// delete	j;
	// delete	i;

	// Animal	*Animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
	// Animal	*AnimalsCpy = new Animal(*Animals[0]);
	// for(int i = 0;i < 4;i++)
	// 	delete	Animals[i];
	// delete AnimalsCpy;
	Dog	a;
	Dog	b(a);
	return 0;
}