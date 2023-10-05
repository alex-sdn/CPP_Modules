#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	std::cout << " [TEST 1] New bureaucrat with grade 165:" << std::endl;

	try {
		Bureaucrat test("LowGuy", 165);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << " [TEST 2] Incrementing grade past 1:" << std::endl;

	Bureaucrat test("Guy2", 2);
	std::cout << test << std::endl;

	std::cout << std::endl << "upGrade() call." << std::endl;
	test.upGrade();
	std::cout << test << std::endl;

	std::cout << std::endl << "upGrade() call." << std::endl;
	test.upGrade();
	std::cout << test << std::endl;

	return 0;
}
