#include "Span.hpp"
#include <iostream>

int main(void)
{
	std::cout << " [TEST 1] Subject main" << std::endl;
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

	std::cout << std::endl << " [TEST 2] FullSpan exception" << std::endl;
	try {
		Span sp = Span(2);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (std::exception & e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

	std::cout << std::endl << " [TEST 3] TooSmall exception" << std::endl;
	try {
		Span sp = Span(5);

		sp.addNumber(1);
		
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

	std::cout << std::endl << " [TEST 4] Insert 20k at once" << std::endl;
	try {
		Span sp = Span(20005);
		sp.addNumber(1);
		sp.addNumber(2);

		std::vector<int> big(20000, 10);
		sp.insertNumbers(big.begin(), big.end());
		
		std::cout << "Size: " << sp.getSpan().size() << std::endl;
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "EXCEPTION: " << e.what() << std::endl;
	}

	return 0;
}