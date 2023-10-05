#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	std::cout << " [TEST ON LIST]" << std::endl;
	
	std::list<int>	lst; // = {1, 2, 3, 42, 5};
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(42);
	lst.push_back(5);
	
	std::list<int>::const_iterator	pos_lst;

	pos_lst = easyfind(lst, 42);
	std::cout << *pos_lst << std::endl;

	std::cout << std::endl << " [TEST ON VECTOR]" << std::endl;

	std::vector<int>	vec; // = {9, 8, 7, 6};
	vec.push_back(9);
	vec.push_back(8);
	vec.push_back(7);
	vec.push_back(6);

	std::vector<int>::const_iterator pos_vec;

	pos_vec = easyfind(vec, 42);
	if (pos_vec == vec.end())
		std::cout << "Couldn't find 42 in vec" << std::endl;

	return 0;
}