#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
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
	return ("Grade too high.");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw ()
{
	return ("Grade too low.");
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

void	Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
	}
	catch (std::exception & e) {
		std::cout << _name << " couldn't sign '" << form.getName() << "' because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed '" << form.getName() << "'." << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
	}
	catch (std::exception & e) {
		std::cout << _name << " could't execute '" << form.getName() << "' because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " executed '" << form.getName() << "'." << std::endl;
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return o;
}
