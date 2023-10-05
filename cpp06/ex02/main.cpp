#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base*	generate(void)
{
	Base*	ptr;

	std::srand(std::time(0));
	int randnum = std::rand() % 3;

	if (randnum == 0) {
		ptr = new A;
		return ptr;
	}
	else if (randnum == 1) {
		ptr = new B;
		return ptr;
	}
	ptr = new C;
	return ptr;
}

void	identify(Base* p)
{
	std::cout << " IDENTIFYING POINTER:" << std::endl;

	if (dynamic_cast<A*>(p))
		std::cout << "Real type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Real type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Real type is C" << std::endl;
}

void	identify(Base& p)
{
	std::cout << std::endl << " IDENTIFYING REFERENCE:" << std::endl;
	
	try {
		A& a = (dynamic_cast<A&>(p));
		std::cout << "Real type is A" << std::endl;
		(void)a;
		return ;
	}
	catch (std::exception & e) {
		std::cout << e.what() << " not A" << std::endl; 
	}
	try {
		B& b = (dynamic_cast<B&>(p));
		std::cout << "Real type is B" << std::endl;
		(void)b;
		return ;
	}
	catch (std::exception & e) {
		std::cout << e.what() << " not B" << std::endl; 
	}
	try {
		C& c = (dynamic_cast<C&>(p));
		std::cout << "Real type is C" << std::endl;
		(void)c;
		return ;
	}
	catch (std::exception & e) {
		std::cout << e.what() << " not C" << std::endl; 
	}	
}

int main(void)
{
	Base*	ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;

	return 0;
}
