#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <deque>
# include <utility>
# include <algorithm>
# include <iterator>
# include <exception>
# include <sstream>
# include <limits>
# include <sys/time.h>
# include <cmath>

# define BOLD "\033[1m"
# define YELLOW "\033[1;93m"
# define RESET "\033[0m"

# define USAGE "Usage: ./PmergeMe [positive integer sequence]"
# define MAX_SIZE_REACHED "Maximum of 4000 integers has been reached"
# define ERR_DUP_VALUES "Error: duplicate values are not allowed"

# define MAX_SIZE 4000
# define MICRO_SEC 1000000.0
# define WHITESPACE "\t\n\v\f\r "

extern clock_t g_startTime;

enum	e_Type
{
	DEQUE_TYPE = 1,
	VECTOR_TYPE = 2
};

enum	e_Mode
{
	EXTRACT_MIN = 1,
	SORT_MAX = 2
};

template <typename T>
struct ContainerTypeTraits;

template <>
struct ContainerTypeTraits< std::deque<int> >
{
	static const e_Type type = DEQUE_TYPE;
};

template <>
struct ContainerTypeTraits< std::vector<int> >
{
	static const e_Type type = VECTOR_TYPE;
};

template <typename T>
class PmergeMe
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string               _rawSequence;

	static const e_Type       _type = ContainerTypeTraits<T>::type;
	T                         _mainChain;

//	==================== Private Methods ========================

	void    parseSequence();
	bool    isSequenceEmpty() const;
	void    mergeInsertSort(size_t, size_t);
	void    insertSorted(size_t, size_t, int);

/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Canonical Form =========================

	PmergeMe();
	PmergeMe(const PmergeMe<T>&);
	~PmergeMe();
	PmergeMe<T>&	operator=(const PmergeMe<T>&);
	
//	==================== Custom Constructors ====================

	PmergeMe(const std::string&);

//	==================== Getters / Setters ======================

	double                     getTime() const;
	const T&                   getContainer() const;
	const std::string          getContainerName() const;

//	==================== Public Methods =========================

	void    printBefore() const;
	void	process();

//	======================= Typedefs ============================

	typedef typename T::iterator             iterator;
	typedef typename T::const_iterator       const_iterator;
};

# include "PmergeMe.tpp"
