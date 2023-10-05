#include "Animal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : _type("Undefined")
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal&	AAnimal::operator=(AAnimal const & rhs)
{
	this->_type = rhs.getType();
	return *this;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return this->_type;
}
