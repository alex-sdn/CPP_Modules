#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong arg count." << std::endl;
		return 1;
	}

	try {
		RPN	rpn(av[1]);
		rpn.calculate();
	}
	catch (std::exception & e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	return 0;
}