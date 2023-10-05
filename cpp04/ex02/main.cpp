#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
// OK
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	
	delete j;
	delete i;

// WON'T WORK
	// const AAnimal* k = new AAnimal();
	// delete k;

	return 0;
}
