#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
	// constructor
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm("Robotomy Request Form", 72, 45)
{
	*this = src;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	_target = rhs.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// destructor
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return _target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw AForm::FormUnsignedException();
	else if (executor.getGrade() > getExecMin())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "* DRILLING NOISES *" << std::endl;
		std::srand(std::time(0));
		int randnum = std::rand() % 2;
		if (randnum)
			std::cout << _target << " has been successfully robotomized." << std::endl;
		else
			std::cout << "Failed to robotomize " << _target << "." << std::endl;
	}
}
