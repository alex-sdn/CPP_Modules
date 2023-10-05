#include "iter.hpp"
#include <iostream>

template <typename T>
void	demo(T & n)
{
	n *= 10;
}

int	main(void)
{
	std::cout << "[ DEMO INTEGER ]" << std::endl;
	int tab[5] = { 1, 2, 3, 10, 42 };

	std::cout << " BEFORE:" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << tab[i] << std::endl;
	std::cout << std::endl;

	iter(tab, 5, &demo);

	std::cout << " AFTER:" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << tab[i] << std::endl;
	std::cout << std::endl;

	std::cout << "[ DEMO FLOAT ]" << std::endl;
	float tab2[4] = { 1.23f, 4.2f, 3.1415f, 456.789f };

	std::cout << " BEFORE:" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << tab2[i] << std::endl;
	std::cout << std::endl;

	iter(tab2, 4, &demo);

	std::cout << " AFTER:" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << tab2[i] << std::endl;
	std::cout << std::endl;

	return 0;
}
