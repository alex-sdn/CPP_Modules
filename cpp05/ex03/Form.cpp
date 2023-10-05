#include "Form.hpp"
#include <iostream>

AForm::AForm(std::string name, int sign, int exec) : _name(name), _signed(false),
												   _signMin(sign), _execMin(exec)
{
	if (_signMin < 1)
		throw AForm::GradeTooHighException();
	else if (_signMin > 150)
		throw AForm::GradeTooLowException();
	if (_execMin < 1)
		throw AForm::GradeTooHighException();
	else if (_execMin > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src.getName()), _signed(src.getSigned()), _signMin(src.getSignMin()), _execMin(src.getExecMin())
{
	*this = src;
}

AForm&	AForm::operator=(AForm const & rhs)
{
	_signed = rhs.getSigned();
	return *this;
}

AForm::~AForm(void)
{
	// destructor
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}

const char* AForm::FormUnsignedException::what(void) const throw()
{
	return ("Form isn't signed.");
}

std::string	AForm::getName(void) const
{
	return _name;
}

bool	AForm::getSigned(void) const
{
	return _signed;
}

int		AForm::getSignMin(void) const
{
	return _signMin;
}

int		AForm::getExecMin(void) const
{
	return _execMin;
}

void	AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _signMin)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

std::ostream &	operator<<(std::ostream & o, AForm const & rhs)
{
	o << "Form: '" << rhs.getName();
	if (rhs.getSigned())
		o << "', Status: signed, ";
	else
		o << "', Status: unsigned, ";
	o << "Signing grade: " << rhs.getSignMin() << ", Exec grade: " << rhs.getExecMin() << ".";
	return o;
}
