#include "MutantStack.hpp"
#include <iostream>

int main(void)
{
	std::cout << " [TEST 1] Subject main" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size: " << mstack.size() << std::endl << std::endl;

	mstack.push(3);
	mstack.push(737);
	mstack.push(42);
	mstack.push(12345);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << std::endl << " [TEST 2] Replace a number with iterators" << std::endl;

	MutantStack<int>::iterator it2 = mstack.begin();

	while (*it2 != 42)
		++it2;
	*it2 = 999999;

	MutantStack<int>::iterator it3 = mstack.begin();

	while (it3 != ite)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}

	std::cout << std::endl << " [TEST 3] Swap first and last numbers with iterators" << std::endl;

	MutantStack<int>::iterator it4 = mstack.begin();
	
	--ite;
	int tmp = *it4;
	*it4 = *ite;
	*ite = tmp;
	
	std::cout << "bottom: " << *it4 << std::endl;
	std::cout << "top: " << mstack.top() << std::endl;

	return 0;
}
