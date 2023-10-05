#include "RPN.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

RPN::RPN(void) : _expression(NULL)
{
	// default constructor
}

RPN::RPN(std::string expression) : _expression(expression)
{
	// constructor
}

RPN::RPN(RPN const & src)
{
	*this = src;
}

RPN&	RPN::operator=(RPN const & rhs)
{
	_expression = rhs.getExpression();
	return *this;
}

RPN::~RPN(void)
{
	// destructor
}

std::string	RPN::getExpression(void) const
{
	return _expression;
}

void	RPN::calculate(void)
{
	_checkFormat();

	std::stack<int, std::list<int> >	stk;
	void			(RPN::*f[4])(std::stack<int, std::list<int> >&) = { &RPN::_sum, &RPN::_sub, &RPN::_div, &RPN::_mult };
	char			type[4] = { '+', '-', '/', '*' };

	for (int i = 0; _expression[i]; i++)
	{
		if (isdigit(_expression[i]))
			stk.push(static_cast<int>(_expression[i] - 48));

		else if (_expression[i] != ' ' && stk.size() > 1)
			for (int j = 0; j < 4; j++)
				if (_expression[i] == type[j])
					(this->*f[j])(stk);
	}

	if (stk.size() == 1)
		std::cout << stk.top() << std::endl;
	else
		std::cout << "ERROR: Stack size is >1" << std::endl;
}

void	RPN::_checkFormat(void) const
{
	// Check valid characters
	int i = 0;
	while (_expression[i])
	{
		if (!isdigit(_expression[i]) && !strchr("+-/*", _expression[i]))
			throw RPN::InvalidCharacterException();
		if (_expression[++i] && _expression[i] != ' ')
			throw RPN::InvalidCharacterException();
		if (_expression[i])
			i++;
	}
}

void	RPN::_sum(std::stack<int, std::list<int> > &stk)
{
	int ope = stk.top();
	
	stk.pop();

	stk.top() += ope;
}

void	RPN::_sub(std::stack<int, std::list<int> > &stk)
{
	int ope = stk.top();
	
	stk.pop();

	stk.top() -= ope;
}

void	RPN::_div(std::stack<int, std::list<int> > &stk)
{
	int ope = stk.top();
	
	if (ope == 0)
		throw RPN::DivisionByZero();
	
	stk.pop();

	stk.top() /= ope;
}

void	RPN::_mult(std::stack<int, std::list<int> > &stk)
{
	int ope = stk.top();
	
	stk.pop();

	stk.top() *= ope;
}

// EXCEPTIONS
const char* RPN::InvalidCharacterException::what(void) const throw()
{
	return ("Invalid character found.");
}

const char* RPN::WrongTokenCount::what(void) const throw()
{
	return ("Wrong token count.");
}

const char* RPN::DivisionByZero::what(void) const throw()
{
	return ("Division by zero.");
}
