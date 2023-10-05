#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria("ice")
{
	*this = src;
}

Ice&	Ice::operator=(Ice const & rhs)
{
	(void)rhs;
	return *this;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria*	Ice::clone(void) const
{
	AMateria* clone = new Ice(*this);

	return clone;
}
