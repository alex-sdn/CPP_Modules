#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat	boss("Boss", 6);
	Intern		intern;

	AForm*	RoboTest = intern.makeForm("robotomy request", "bender");

	boss.signForm(*RoboTest);
	boss.executeForm(*RoboTest);

	std::cout << std::endl;
	AForm*	FakeTest = intern.makeForm("fake form", "target");
	if (!FakeTest)
		std::cout << "FakeForm pointer is NULL." << std::endl; 

	delete RoboTest;

	return 0;
}
