#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	// GOOD
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;

	// BAD
	// const WrongAnimal* wrongmeta = new WrongAnimal();
	// const WrongAnimal* wrongcat = new WrongCat();

	// std::cout << std::endl;

	// std::cout << wrongcat->getType() << " " << std::endl;
	// wrongcat->makeSound(); //will output the animal sound!
	// wrongmeta->makeSound();

	// std::cout << std::endl;

	// delete wrongmeta;
	// delete wrongcat;

	return 0;
}
