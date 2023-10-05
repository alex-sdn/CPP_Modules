#include "Form.hpp"
#include <iostream>

Form::Form(std::string name, int sign, int exec) : _name(name), _signed(false),
												   _signMin(sign), _execMin(exec)
{
	if (_signMin < 1)
		throw Form::GradeTooHighException();
	else if (_signMin > 150)
		throw Form::GradeTooLowException();
	if (_execMin < 1)
		throw Form::GradeTooHighException();
	else if (_execMin > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src.getName()), _signed(src.getSigned()), _signMin(src.getSignMin()), _execMin(src.getExecMin())
{
	*this = src;
}

Form&	Form::operator=(Form const & rhs)
{
	_signed = rhs.getSigned();
	return *this;
}

Form::~Form(void)
{
	// destructor
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}

std::string	Form::getName(void) const
{
	return _name;
}

bool	Form::getSigned(void) const
{
	return _signed;
}

int		Form::getSignMin(void) const
{
	return _signMin;
}

int		Form::getExecMin(void) const
{
	return _execMin;
}

void	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _signMin)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

std::ostream &	operator<<(std::ostream & o, Form const & rhs)
{
	o << "Form: '" << rhs.getName();
	if (rhs.getSigned())
		o << "', Status: signed, ";
	else
		o << "', Status: unsigned, ";
	o << "Signing grade: " << rhs.getSignMin() << ", Exec grade: " << rhs.getExecMin() << ".";
	return o;
}
