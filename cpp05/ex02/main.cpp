#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat	boss("Boss", 6);
	Bureaucrat	guy("Guy", 140);
	std::cout << boss << std::endl;
	std::cout << guy << std::endl;
	ShrubberyCreationForm	ShrubTest("ShrubTarget");
	RobotomyRequestForm		RoboTest("RoboTarget");
	PresidentialPardonForm	PresTest("PresTarget");
	std::cout << ShrubTest << std::endl;
	std::cout << RoboTest << std::endl;
	std::cout << PresTest << std::endl;

	std::cout << std::endl << " [TEST 1] GUY and Shrubbery Form:" << std::endl;
	guy.signForm(ShrubTest);
	guy.executeForm(ShrubTest);

	std::cout << std::endl << " [TEST 2] BOSS and Shrubbery Form:" << std::endl;
	boss.executeForm(ShrubTest);

	std::cout << std::endl << " [TEST 3] GUY and Robotomy Form:" << std::endl;
	guy.signForm(RoboTest);

	std::cout << std::endl << " [TEST 4] BOSS and Robotomy Form:" << std::endl;
	boss.executeForm(RoboTest);
	boss.signForm(RoboTest);
	boss.executeForm(RoboTest);

	std::cout << std::endl << " [TEST 5] BOSS and Presidential Form:" << std::endl;
	boss.signForm(PresTest);
	boss.executeForm(PresTest);
	std::cout << "upGrade() call." << std::endl;
	boss.upGrade();
	boss.executeForm(PresTest);

	return 0;
}
