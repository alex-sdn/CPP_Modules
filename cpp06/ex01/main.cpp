#include "Serializer.hpp"
#include <iostream>
#include <cstdlib>

void	print_data(Data* data)
{
	std::cout << "n: " << data->n << std::endl;
	std::cout << "f: " << data->f << std::endl;
	std::cout << "c: " << data->c << std::endl;
	std::cout << "str: " << data->str << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	//CREATE STRUCT
	Data*	start_struct = new Data;
	if (!start_struct)
		return 1;
	start_struct->n = 42;
	start_struct->f = 4.2f;
	start_struct->c = 'a';
	start_struct->str = "Hello";

	std::cout << " BEFORE" << std::endl;
	print_data(start_struct);

	uintptr_t	raw_struct = Serializer::serialize(start_struct);
	Data*		end_struct = Serializer::deserialize(raw_struct);

	std::cout << " AFTER" << std::endl;
	print_data(end_struct);

	delete start_struct;

	return 0;
}