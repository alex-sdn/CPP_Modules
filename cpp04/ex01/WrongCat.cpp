#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->_type = "WrongCat";
	this->_brain = new Brain();
}

WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat&	WrongCat::operator=(WrongCat const & rhs)
{
	this->_type = rhs.getType();
	this->_brain = rhs.getBrain();
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	delete this->_brain;
}

Brain*	WrongCat::getBrain(void) const
{
	return this->_brain;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "* Meow Meow! *" << std::endl;
}