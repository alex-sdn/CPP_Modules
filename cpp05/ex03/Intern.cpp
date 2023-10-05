#include "Intern.hpp"
#include <iostream>

Intern::Intern(void)
{
	// constructor
}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern&	Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

Intern::~Intern(void)
{
	// destructor
}

AForm*	Intern::makeForm(std::string type, std::string target)
{
	AForm*		(Intern::*f[4])(std::string target) = { &Intern::_newShrubberyForm, &Intern::_newRobotomyForm, &Intern::_newPresidentialForm };
	std::string	types[3] = { "shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++)
		if (types[i] == type)
			return (this->*f[i])(target);
	std::cout << "Intern couldn't find a form of type '" << type << "'." << std::endl;
	return (0);
}

AForm*	Intern::_newShrubberyForm(std::string target)
{
	std::cout << "Intern creates Shrubbery Creation Form." << std::endl;
	AForm*	form = new ShrubberyCreationForm(target);
	return form;
}

AForm*	Intern::_newRobotomyForm(std::string target)
{
	std::cout << "Intern creates Robotomy Request Form." << std::endl;
	AForm*	form = new RobotomyRequestForm(target);
	return form;
}

AForm*	Intern::_newPresidentialForm(std::string target)
{
	std::cout << "Intern creates Presidential Pardon Form." << std::endl;
	AForm*	form = new PresidentialPardonForm(target);
	return form;
}
