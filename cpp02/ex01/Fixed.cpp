#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_nBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
	// Default constructor
}

Fixed::Fixed(int const nbr) : _rawBits(nbr << _nBits)
{
	// int constructor
}

Fixed::Fixed(float const nbr) : _rawBits((roundf)(nbr * (1 << _nBits)))
{
	// float constructor
}

Fixed::Fixed(Fixed const & src)
{
	// Copy constructor
	this->_rawBits = src.getRawBits();
}

Fixed::~Fixed(void)
{
	// Destructor
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	// Copy assignement operator
	this->_rawBits = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->_rawBits / (1 << _nBits);
}

int	Fixed::toInt(void) const
{
	return this->_rawBits >> _nBits;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
