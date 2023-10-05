#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	std::cout << "Cat constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const & src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = src.getType();
	this->_brain = new Brain();
	*(this->_brain) = *(src._brain);
}

Cat&	Cat::operator=(Cat const & rhs)
{
	this->_type = rhs.getType();
	if (this->_brain)
		delete this->_brain;
	this->_brain = new Brain();
	*(this->_brain) = *(rhs._brain);
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Brain*	Cat::getBrain(void) const
{
	return this->_brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "* Meow Meow! *" << std::endl;
}