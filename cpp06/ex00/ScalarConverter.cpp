#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter(void)
{
	// constructor
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	// destructor
}

void	ScalarConverter::convert(std::string arg)
{
	int _type = _findType(arg);

	switch(_type) {
		case T_CHAR :
			_printChar(arg[0]);
			break;
		case T_INT :
			_printInt(atoi(arg.c_str()));
			break;
		case T_FLOAT :
			_printFloat(_strToFloat(arg));
			break ;
		case T_DOUBLE :
			_printDouble(atof(arg.c_str()));
			break;
		case T_MINF :
			_printMinf();
			break;
		case T_PINF :
			_printPinf();
			break;
		case T_NAN :
			_printNan();
			break;
		default :
			std::cout << "Couldn't detect type." << std::endl;
	}
}

int	ScalarConverter::_findType(std::string arg)
{
	int	len = arg.size();
	int	i = -1;
	int	dot_count = 0;

	// CHECK PSEUDO LITERALS
	if (arg == "-inff" || arg == "-inf")
		return T_MINF;
	if (arg == "+inff" || arg == "+inf" || arg == "inff" || arg == "inf")
		return T_PINF;
	if (arg == "nanf" || arg == "nan")
		return T_NAN;

	// CHECK CHAR
	if (len == 1 && (arg[0] < '0' || arg[0] > '9'))
		return T_CHAR;

	// CHECK INT
	while (++i < len)
		if ((arg[i] < '0' || arg[i] > '9') && !(i == 0 && arg[i] == '-' && arg[1]))
			break ;
	if (!arg[i])
		return _checkInt(arg);

	// CHECK DOUBLE
	i = -1;
	while (++i < len)
	{
		if (arg[i] == '.')
			dot_count++;
		else if ((arg[i] < '0' || arg[i] > '9') && !(i == 0 && arg[i] == '-' && arg[1]))
			break;
	}
	if (!arg[i] && dot_count == 1)
		return _checkDouble(arg);

	// CHECK FLOAT
	if (i > 1 && arg[i] == 'f' && !arg[i + 1] && dot_count == 1)
		return _checkFloat(arg);
	
	return T_WRONG;
}

int	ScalarConverter::_checkInt(std::string arg)
{
	long int	check = strtol(arg.c_str(), 0, 10);
	
	if (check < std::numeric_limits<int>::min() || check > std::numeric_limits<int>::max())
		return T_WRONG;
	return T_INT;
}

int	ScalarConverter::_checkDouble(std::string arg)
{
	double	check = strtod(arg.c_str(), 0);

	if (check == HUGE_VAL || check == -HUGE_VAL)
		return T_WRONG;
	return T_DOUBLE;
}

int	ScalarConverter::_checkFloat(std::string arg)
{
	if (_checkDouble(arg) == T_WRONG)
		return T_WRONG;
	
	double	check = strtod(arg.c_str(), 0);
	if (check < std::numeric_limits<float>::min() || check > std::numeric_limits<float>::max())
		return T_WRONG;
	return T_FLOAT;
}

float	ScalarConverter::_strToFloat(std::string& str)
{
	std::istringstream	iss(str);
	float				n;

	iss >> n;
	return n;
}

void	ScalarConverter::_printChar(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::_printInt(int n)
{
	if (n < 32 || n > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void	ScalarConverter::_printFloat(float n)
{
	if (static_cast<int>(n) != n || n < 32 || n > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;

	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;

	std::cout << "float: " << n;
	if (n - static_cast<int>(n) == 0)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(n);
	if (n - static_cast<int>(n) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::_printDouble(double n)
{
	if (static_cast<int>(n) != n || n < 32 || n > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;

	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;

	if (n < std::numeric_limits<float>::min() || n > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else {
		std::cout << "float: " << static_cast<float>(n);
		if (n - static_cast<int>(n) == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}

	std::cout << "double: " << n;
	if (n - static_cast<int>(n) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::_printMinf(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void	ScalarConverter::_printPinf(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

void	ScalarConverter::_printNan(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}
