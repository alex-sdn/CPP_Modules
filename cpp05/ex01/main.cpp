#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout << " [TEST 1] New form with signMin 0:" << std::endl;
	try {
		Form	form1("thing", 0, 100);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << " [TEST 2] New form with execMin 165:" << std::endl;
	try {
		Form	form1("thing", 100, 165);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	Bureaucrat	guy("Guy", 101);
	std::cout << guy << std::endl;
	Form		test("TestForm", 100, 80);
	std::cout << test << std::endl;

	std::cout << std::endl << " [Test 3] Guy signs 'TestForm':" << std::endl;
	guy.signForm(test);

	std::cout << std::endl << " FORM STATUS CHECK:" << std::endl;
	std::cout << test << std::endl;

	std::cout << std::endl << "upGrade() call." << std::endl;
	guy.upGrade();
	std::cout << guy << std::endl;

	guy.signForm(test);
	
	std::cout << std::endl << " FORM STATUS CHECK:" << std::endl;
	std::cout << test << std::endl;

	return 0;
}
