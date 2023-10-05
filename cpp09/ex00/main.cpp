#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Need one infile as argument." << std::endl;
		return 1;
	}

	BitcoinExchange	btc;

	btc.initData();
	btc.getRates(av[1]);

	return 0;
}