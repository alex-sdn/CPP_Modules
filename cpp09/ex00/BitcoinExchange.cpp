#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

BitcoinExchange::BitcoinExchange(void)
{
	// constructor
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	_data = rhs.getData();
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	// destructor
}

std::map<int, double>	BitcoinExchange::getData(void) const
{
	return _data;
}

void	BitcoinExchange::initData(void)
{
	// OPEN .CSV
	std::ifstream	ifs;
	ifs.open("data.csv", std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cout << "Couldn't open .csv file" << std::endl;
		return ;
	}

	// FILL MAP
	std::string	line;
	std::string	date;
	std::string	price;
	int			numDate;

	getline(ifs, line);
	while (getline(ifs, line))
	{
		date = line.substr(0, line.find(','));
		price = line.substr(line.find(',') + 1, std::string::npos);

		try {
			numDate = _convertDate(date);
			_data[numDate] = atof(price.c_str());
		}
		catch (std::exception & e) {
			std::cout << "ERROR: " << e.what() << date << ")" << std::endl;
		}
	}

	ifs.close();
}

void	BitcoinExchange::getRates(char *infile)
{
	if (_data.empty()) return ;

	// OPEN INPUT
	std::ifstream	ifs;
	ifs.open(infile, std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cout << "Couldn't open input file" << std::endl;
		return ;
	}

	// PRINT VALUES
	std::string line;
	std::string date;
	std::string amount;
	int			numDate;
	double		numAmount;

	while (getline(ifs, line))
	{
		if (line.find('|') != std::string::npos)
		{
			date = line.substr(0, line.find('|'));
			date = date.substr(date.find_first_not_of(' '), date.find_last_not_of(' ') + 1);
			amount = line.substr(line.find('|') + 1, std::string::npos);
			amount = amount.substr(amount.find_first_not_of(' '), amount.find_last_of("0123456789"));

			try {
				numDate = _convertDate(date);
				numAmount = _convertAmount(amount);

				std::map<int, double>::iterator it;
				it = _data.find(numDate);
				if (it == _data.end())
				{
					it = _data.lower_bound(numDate);
					if (it == _data.begin())
						throw BitcoinExchange::DateTooEarly();
					it--;
				}
				std::cout << date << " => " << numAmount << " = " << it->second * numAmount << std::endl;
			}
			catch (std::exception & e) {
				std::cout << "ERROR: " << e.what();
				if (!strcmp(e.what(), "bad date format (") || !strcmp(e.what(), "date is too early. ("))
					std::cout << date << ")" << std::endl;
				else
					std::cout << amount << ")" << std::endl;
			}
		}
		else
			std::cout << "ERROR: line doesn't follow 'date | value' format." << std::endl;
	}

	ifs.close();
}

int		BitcoinExchange::_convertDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		throw BitcoinExchange::WrongDateFormat();

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 7).c_str());
	int day = atoi(date.substr(8, 10).c_str());

	if (month > 12 || day > 31 || month == 0 || day == 0)
		throw BitcoinExchange::WrongDateFormat();

	return (year * 10000 + month * 100 + day);
}

double	BitcoinExchange::_convertAmount(std::string amount)
{
	int dot_count = 0;
	int i = -1;
	// Check format
	if (amount[0] == '-')
		i++;
	while (amount[++i])
	{
		if (amount[i] == '.')
			dot_count++;
		else if (!isdigit(amount[i]))
			throw BitcoinExchange::ValueIncorrect();
	}
	if (dot_count > 1)
		throw BitcoinExchange::ValueIncorrect();

	// Check range
	double num = atof(amount.c_str());
	if (num < 0)
		throw BitcoinExchange::ValueTooSmall();
	else if (num > 1000)
		throw BitcoinExchange::ValueTooBig();
	
	return num;
}

// EXCEPTIONS
const char* BitcoinExchange::ValueTooSmall::what(void) const throw()
{
	return ("not a positive number (");
}

const char* BitcoinExchange::ValueTooBig::what(void) const throw()
{
	return ("too large a number (");
}

const char* BitcoinExchange::ValueIncorrect::what(void) const throw()
{
	return ("incorrect value format (");
}

const char* BitcoinExchange::WrongDateFormat::what(void) const throw()
{
	return ("bad date format (");
}

const char* BitcoinExchange::WrongLineFormat::what(void) const throw()
{
	return ("Line doesn't follow 'date | value' format.");
}

const char* BitcoinExchange::DateTooEarly::what(void) const throw()
{
	return ("date is too early. (");
}
