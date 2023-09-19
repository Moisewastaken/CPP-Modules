#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int main( void )
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal *wrong = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << "J Type: " << j->getType() << std::endl;
	std::cout << "I Type: " << i->getType() << std::endl;
	std::cout << "Meta type: " << meta->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	std::cout << "WrongAnimal Type: " << wrong->getType() << std::endl;
	std::cout << "WrongCat Type: " << wrongCat->getType() << std::endl;
	wrong->makeSound();
	wrongCat->makeSound();

	delete  meta;
	delete  j;
	delete  i;
	delete  wrong;
	delete  wrongCat;
	return 0;
}