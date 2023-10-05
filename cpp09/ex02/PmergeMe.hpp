#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <utility>
# include <string>
# include <cstdlib>

class PmergeMe {

	public :

		PmergeMe();
		PmergeMe(PmergeMe const & src);
		PmergeMe& operator=(PmergeMe const & rhs);
		~PmergeMe();

		std::vector<int>	getVec() const;
		std::deque<int>		getDeque() const;

		void				startSorting(char **av);
		void				sortVec(char **av);
		void				sortDeque(char **av);

		class	NotADigit : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class	IntegerOverflow : public std::exception {
			public :
				virtual const char* what() const throw();
		};

	private :

		std::vector<int>	_vec;
		std::deque<int>		_deque;

		void		_fordJohnsonSortVector(std::vector<int> &array);
		void		_fordJohnsonSortDeque(std::deque<int> &array);
		template <typename T>
		void		_addPair(T &Pairs, int a, int b);
		template <typename T>
		void		_sortPairs(T &Pairs);
		template <typename T>
		void		_insertionSort(T &array);
		template <typename T>
		void		_mergeSort(T &array, T &left, T &right);
		template <typename T>
		void		_binarySearchInsert(T &array, int nbr, int limit);
	
		template <typename T>
		void		_fillContainer(T &container, char **av);
		void		_checkOverflow(int nbr, char *str) const;

};

#endif