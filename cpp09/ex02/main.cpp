#include "PmergeMe.hpp"
#include <iostream>

// ./PmergeMe $(shuf -i 3-3000 -n 1) $(shuf -i 1-10000 -n $(shuf -i 3-3000 -n 1) | tr "\n" " ")

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Please input a positive integer sequence as argument." << std::endl;
		return 1;
	}

	PmergeMe	algo;

	try {
		algo.startSorting(av);
	}
	catch (std::exception & e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	return 0;
}
