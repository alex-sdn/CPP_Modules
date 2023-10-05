#include <iostream>
#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define MAX_VAL 750
int main(int, char**)
{
// MAIN SUJET
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;

// MY MAIN
	// Array<int>	demo(3);

	// // OUT OF RANGE TEST
	// try {
	// 	demo[0] = 1;
	// 	demo[1] = 42;
	// 	demo[2] = 3;
	// 	demo[3] = 9999999;
	// }
	// catch (std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// // DEEP COPY TEST
	// Array<int>	copy = demo;

	// for (unsigned int i = 0; i < copy.size(); i++)
	// 	copy[i] *= 10;
	
	// std::cout << std::endl << "DEMO | COPY" << std::endl;
	// for (unsigned int i = 0; i < demo.size(); i++)
	// 	std::cout << std::setw(4) << demo[i] << " |" << std::setw(5) << copy[i] << std::endl;
	
	// return 0;
}