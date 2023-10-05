#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span(void) : _maxSize(0)
{
	// default constructor
}

Span::Span(unsigned int N) : _maxSize(N)
{
	// constructor
}

Span::Span(Span const & src)
{
	_maxSize = src.getMaxSize();
	_span = src.getSpan();
}

Span&	Span::operator=(Span const & rhs)
{
	_maxSize = rhs.getMaxSize();
	_span = rhs.getSpan();
	return *this;
}

Span::~Span(void)
{
	// destructor
}

unsigned int	Span::getMaxSize(void) const
{
	return _maxSize;
}

std::vector<int>	Span::getSpan(void) const
{
	return _span;
}

void	Span::addNumber(int n)
{
	if (_span.size() < _maxSize)
		_span.push_back(n);
	else
		throw Span::FullSpanException();
}

void	Span::insertNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_span.size() + end - begin > _maxSize)
		throw Span::FullSpanException();

	_span.insert(_span.end(), begin, end);
}

int		Span::shortestSpan()
{
	if (_span.size() < 2)
		throw Span::SpanTooSmallException();

	int	shortest = std::max(_span[1], _span[0]) - std::min(_span[1], _span[0]);
	for (long unsigned int i = 0; i < _span.size() - 1; i++)
	{
		for (long unsigned int j = i + 1; j < _span.size(); j++)
		{
			int tmp = std::max(_span[i], _span[j]) - std::min(_span[i], _span[j]);
			if (tmp < shortest)
				shortest = tmp;
		}
	}
	return shortest;
}

int		Span::longestSpan()
{
	if (_span.size() < 2)
		throw Span::SpanTooSmallException();

	int	longest = std::max(_span[1], _span[0]) - std::min(_span[1], _span[0]);
	for (long unsigned int i = 0; i < _span.size() - 1; i++)
	{
		for (long unsigned int j = 1; j < _span.size(); j++)
		{
			int tmp = std::max(_span[i], _span[j]) - std::min(_span[i], _span[j]);
			if (tmp > longest)
				longest = tmp;
		}
	}
	return longest;
}

const char* Span::FullSpanException::what(void) const throw()
{
	return ("Span is full.");
}

const char*	Span::SpanTooSmallException::what(void) const throw()
{
	return ("Not enough numbers in Span.");
}
