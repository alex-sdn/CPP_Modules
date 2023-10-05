#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe(void)
{
	// constructor
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
}

PmergeMe&	PmergeMe::operator=(PmergeMe const & rhs)
{
	_vec = rhs.getVec();
	_deque = rhs.getDeque();
	return *this;
}

PmergeMe::~PmergeMe(void)
{
	// destructor
}

std::vector<int>	PmergeMe::getVec(void) const
{
	return _vec;
}

std::deque<int>		PmergeMe::getDeque(void) const
{
	return _deque;
}

void	PmergeMe::startSorting(char **av)
{
	_fillContainer(_vec, av);

	std::cout << "BEFORE: ";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
        std::cout << *it << " ";
	std::cout << std::endl;

	_vec.clear();

	sortVec(av);
	sortDeque(av);
}

void	PmergeMe::sortVec(char **av)
{
	clock_t		timer;
	double		sortTime;

	timer = clock();

	_fillContainer(_vec, av);
	_fordJohnsonSortVector(_vec);

	timer = clock() - timer;
	sortTime = static_cast<double>(timer) / CLOCKS_PER_SEC * 1000000;

	std::cout << "AFTER:  ";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
        std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << sortTime << " μs" << std::endl;
}

void	PmergeMe::sortDeque(char **av)
{
	clock_t		timer;
	double		sortTime;

	timer = clock();

	_fillContainer(_deque, av);
	_fordJohnsonSortDeque(_deque);
	
	timer = clock() - timer;
	sortTime = static_cast<double>(timer) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << sortTime << " μs" << std::endl;
}

/*                      *\
**  ALGO MAIN (VECTOR)  **
\*                      */
void	PmergeMe::_fordJohnsonSortVector(std::vector<int> &array)
{
	if (array.size() == 1)
		return ;

	// make Pairs and sort them by the second value
	std::vector< std::pair<int, int> >	Pairs;

	while (array.size() > 1)
	{
		int tmp = array.back();
		array.pop_back();
		_addPair(Pairs, tmp, array.back());
		array.pop_back();
	}
	_sortPairs(Pairs);

	// push the bigger numbers in sortedArray (+ the first smaller num)
	std::vector<int> sortedArray;

	sortedArray.push_back(Pairs[0].first);
	for (unsigned int i = 0; i < Pairs.size(); i++)
		sortedArray.push_back(Pairs[i].second);

	// push the smaller numbers in pend, sorted in jacobsthal sized vectors
	std::vector< std::vector<int> > pend;
	std::vector<int> jacobsthal;
	unsigned int total = 4;

	jacobsthal.push_back(2);
	jacobsthal.push_back(2);
	for (int i = 1; total < Pairs.size() - 1; i++)
	{
		jacobsthal.push_back(jacobsthal[i - 1] * 2 + jacobsthal[i]);
		total += jacobsthal.back();
	}
	if (Pairs.size() <= 3)
		jacobsthal.pop_back();
	if (Pairs.size() <= 1)
		jacobsthal.pop_back();

	int pairsIdx = 1;
	for (unsigned int i = 0; i < jacobsthal.size(); i++)
	{
		int j = jacobsthal[i];
		if (static_cast<int>(Pairs.size()) < jacobsthal[i] + pairsIdx)
		{
			j = Pairs.size() - pairsIdx;
			if (j < 1)
				j = 1;
		}

		std::vector<int> newVec;
		while (--j >= 0)
		{
			newVec.push_back(Pairs[pairsIdx + j].first);
		}
		pend.push_back(newVec);
		pairsIdx += jacobsthal[i];
	}

	// insert in sortedArray
	int range = 2;
	for (unsigned int i = 0; i < pend.size(); i++)
	{
		range *= 2;
		for (unsigned int j = 0; j < pend[i].size(); j++)
		{
			// insert pend[i][j] in sortedArray[0] - [range - 1];
			_binarySearchInsert(sortedArray, pend[i][j], range - 1);
		}
	}

	// add last number if odd array
	if (array.size() > 0)
		_binarySearchInsert(sortedArray, array[0], sortedArray.size() - 1);

	array = sortedArray;
}

/*                     *\
**  ALGO MAIN (DEQUE)  **
\*                     */
void	PmergeMe::_fordJohnsonSortDeque(std::deque<int> &array)
{
	if (array.size() == 1)
		return ;

	// make Pairs and sort them by the second value
	std::deque< std::pair<int, int> >	Pairs;

	while (array.size() > 1)
	{
		int tmp = array.back();
		array.pop_back();
		_addPair(Pairs, tmp, array.back());
		array.pop_back();
	}
	_sortPairs(Pairs);

	// push the bigger numbers in sortedArray (+ the first smaller num)
	std::deque<int>	sortedArray;

	sortedArray.push_back(Pairs[0].first);
	for (unsigned int i = 0; i < Pairs.size(); i++)
		sortedArray.push_back(Pairs[i].second);

	// push the smaller numbers in pend, sorted in jacobsthal sized deques
	std::deque< std::deque<int> > pend;
	std::deque<int> jacobsthal;
	unsigned int total = 4;

	jacobsthal.push_back(2);
	jacobsthal.push_back(2);
	for (int i = 1; total < Pairs.size() - 1; i++)
	{
		jacobsthal.push_back(jacobsthal[i - 1] * 2 + jacobsthal[i]);
		total += jacobsthal.back();
	}
	if (Pairs.size() <= 3)
		jacobsthal.pop_back();
	if (Pairs.size() <= 1)
		jacobsthal.pop_back();

	int pairsIdx = 1;
	for (unsigned int i = 0; i < jacobsthal.size(); i++)
	{
		int j = jacobsthal[i];
		if (static_cast<int>(Pairs.size()) < jacobsthal[i] + pairsIdx)
		{
			j = Pairs.size() - pairsIdx;
			if (j < 1)
				j = 1;
		}

		std::deque<int> newDeq;
		while (--j >= 0)
		{
			newDeq.push_back(Pairs[pairsIdx + j].first);
		}
		pend.push_back(newDeq);
		pairsIdx += jacobsthal[i];
	}

	// insert in sortedArray
	int range = 2;
	for (unsigned int i = 0; i < pend.size(); i++)
	{
		range *= 2;
		for (unsigned int j = 0; j < pend[i].size(); j++)
		{
			// insert pend[i][j] in sortedArray[0] - [range - 1];
			_binarySearchInsert(sortedArray, pend[i][j], range - 1);
		}
	}

	// add last number if odd array
	if (array.size() > 0)
		_binarySearchInsert(sortedArray, array[0], sortedArray.size() - 1);

	array = sortedArray;
}

template <typename T>
void	PmergeMe::_addPair(T &Pairs, int a, int b)
{
	std::pair<int, int>	newPair;

	if (a < b)
	{
		newPair.first = a;
		newPair.second = b;
	}
	else
	{
		newPair.first = b;
		newPair.second = a;
	}
	Pairs.push_back(newPair);
}

template <typename T>
void	PmergeMe::_sortPairs(T &Pairs)
{
	int size = Pairs.size();

	if (size < 16)
		_insertionSort(Pairs);
	
	else 
	{
		int mid = size / 2;

		T left(Pairs.begin(), Pairs.begin() + mid);
		T right(Pairs.begin() + mid, Pairs.end());

		_sortPairs(left);
		_sortPairs(right);

		_mergeSort(Pairs, left, right);
	}
}

template <typename T>
void	PmergeMe::_insertionSort(T &array)
{
	int size = array.size();

	for (int i = 0; i < size; ++i)
	{
		std::pair<int, int> key = array[i];
		int j = i - 1;

		while (j >= 0 && array[j].second > key.second)
		{
			array[j + 1] = array[j];
			j -= 1;
		}
		array[j + 1] = key;
	}
}

template <typename T>
void	PmergeMe::_mergeSort(T &array, T &left, T &right)
{
	int i = 0, j = 0, k = 0;
	int	leftSize = left.size();
	int rightSize = right.size();

	while (i < leftSize && j < rightSize)
	{
		if (left[i].second <= right[j].second)
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < leftSize)
		array[k++] = left[i++];
	while (j < rightSize)
		array[k++] = right[j++];
}

template <typename T>
void	PmergeMe::_binarySearchInsert(T &array, int nbr, int right)
{
	int left = 0;

	if (right >= static_cast<int>(array.size()))
		right = array.size() - 1;

	if (nbr > array[right])
	{
		array.insert(array.end(), nbr);
		return ;
	}

	while (left <= right)
	{
		int mid = (left + right) / 2;

        if (array[mid] == nbr)
		{
			array.insert(array.begin() + mid, nbr);
            return ;
		}
		else if (array[mid] < nbr)
            left = mid + 1;
        else
            right = mid - 1;
	}

	array.insert(array.begin() + left, nbr);
}

template <typename T>
void	PmergeMe::_fillContainer(T &container, char **av)
{
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
			if (!isdigit(av[i][j]))
				throw PmergeMe::NotADigit();
		container.push_back(atoi(av[i]));
		
		_checkOverflow(container.back(), av[i]);
	}
}

void	PmergeMe::_checkOverflow(int nbr, char *str) const
{
	std::string			converted;
	std::stringstream	ss;

	ss << nbr;
	converted = ss.str();
	if (strcmp(str, converted.c_str()) != 0)
		throw PmergeMe::IntegerOverflow();
}


// EXCEPTIONS
const char* PmergeMe::NotADigit::what(void) const throw()
{
	return ("Character isn't a digit.");
}

const char* PmergeMe::IntegerOverflow::what(void) const throw()
{
	return ("Detected integer overflow.");
}
