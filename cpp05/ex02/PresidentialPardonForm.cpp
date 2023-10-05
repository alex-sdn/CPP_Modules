#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	// constructor
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm("Robotomy Request Form", 25, 5)
{
	*this = src;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	_target = rhs.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// destructor
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return _target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::FormUnsignedException();
	else if (executor.getGrade() > getExecMin())
		throw AForm::GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblerox." << std::endl;
}
