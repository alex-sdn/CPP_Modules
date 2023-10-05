#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
	{
		_grade = 1;  //necessaire ?
		throw Bureaucrat::GradeTooHighException();
	}
	else if (_grade > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs)
{
	_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	// destructor
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw ()
{
	return ("[Bureaucrat] Grade too high.");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw ()
{
	return ("[Bureaucrat] Grade too low.");
}

std::string	Bureaucrat::getName(void) const
{
	return _name;
}

int	Bureaucrat::getGrade(void) const
{
	return _grade;
}

void	Bureaucrat::upGrade(void)
{
	try {
		if (_grade <= 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade--;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::downGrade(void)
{
	try {
		if (_grade >= 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade++;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}
