#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Undefined")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal&	Animal::operator=(Animal const & rhs)
{
	this->_type = rhs.getType();
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return this->_type;
}

void	Animal::makeSound(void) const
{
	std::cout << "* Undefined noises *" << std::endl;
}
