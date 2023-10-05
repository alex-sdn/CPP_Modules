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
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j; //should not leak
	delete i;

// WILL LEAK
	// const WrongAnimal* i = new WrongCat();
	
	// delete i;

// STACK TEST
	// const Dog* dog = new Dog();
	// dog->makeSound();
	// delete dog;

// DEEP COPY: OK
	// Dog	dogtest = Dog();
	// Dog copytest = Dog(dogtest);
	// dogtest.makeSound();

// SHALLOW COPY: DOUBLE FREE
	// WrongCat	cattest = WrongCat();
	// WrongCat	copytest = WrongCat(cattest);
	// copytest.makeSound();

	return 0;
}
