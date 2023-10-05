#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	std::cout << "Dog constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = src.getType();
	this->_brain = new Brain();
	*(this->_brain) = *(src._brain);
}

Dog&	Dog::operator=(Dog const & rhs)
{
	this->_type = rhs.getType();
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain();
	*(this->_brain) = *(rhs._brain);
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Brain*	Dog::getBrain(void) const
{
	return this->_brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "* Woof Woof! *" << std::endl;
}
