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
# include <unistd.h>

# define BOLD "\033[1m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;93m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;95m"
# define RESET "\033[0m"

# define EMPTY "Error: empty sequence in parameter\n"
# define USAGE "Usage: ./PmergeMe [positive integer sequence]"
# define ERR_TYPE "Unsupported container type. Please use vector or deque"
# define MAX_SIZE_REACHED "Maximum of 4000 integers has been reached"
# define ERR_DUP_VALUES "Error: duplicate values are not allowed"

# define MAX_SIZE 4000
# define WHITESPACE "\t\n\v\f\r "

template <typename T>
class PmergeMe;

// GLOBAL VARIABLE
extern clock_t g_startTime;

// ENUM
enum	e_Type
{
	INVALID_TYPE = 0,
	DEQUE_TYPE = 1,
	VECTOR_TYPE = 2
};

enum	e_Mode
{
	HANDLE_SEQUENCE = 1,
	HANDLE_MAINCHAIN = 2
};

// TYPE TRAITS
template <typename T>
struct	ContainerTypeTraits
{
	static const e_Type value = INVALID_TYPE;
};

template <>
struct	ContainerTypeTraits< std::deque< std::pair<int, int> > >
{
	static const e_Type value = DEQUE_TYPE;
};

template <>
struct	ContainerTypeTraits< std::vector< std::pair<int, int> > >
{
	static const e_Type value = VECTOR_TYPE;
};

template <typename T>
class PmergeMe
{
/*****************
*    PRIVATE     *
*****************/
private:

	static const e_Type    _type = ContainerTypeTraits<T>::value;

	std::string            _rawSequence;

	size_t                 _size;

	T                      _sequence;
	T                      _mainChain;

//	====================== Typedefs =============================

	typedef typename T::iterator             iterator;

//	==================== Private Methods ========================

	void                 parseSequence();
	bool                 isSequenceEmpty() const;

	void                 insertErase(T&, T&, iterator);
	void                 insertPending(T&, T&);
	void                 insertValue(T&, iterator, size_t);
	
	bool                 isOdd(T&, T&, size_t);
	void                 setKeys(T&);
	void                 getOrder(std::vector<size_t>&, size_t);
	size_t               jacobsthal(size_t) const;
	iterator             findByKey(T&, int);
	iterator             binarySearch(iterator, iterator);

	double               getDuration() const;
	const std::string    getContainerType() const;
	
//	===================== Debug Methods =========================

	void                 printSequence() const;
	void                 printMainChain() const;
	void                 printPending(T&) const;
	void                 printLeftover(T&) const;
	void                 printOrder(std::vector<size_t>&) const;
	const std::string    isSorted() const;

/*****************
*     PUBLIC     *
*****************/
public:

	PmergeMe();
	PmergeMe(const std::string&);
	PmergeMe(const PmergeMe<T>&);
	~PmergeMe();
	PmergeMe<T>&         operator=(const PmergeMe<T>&);

//	==================== Public Methods =========================

	void                 mergeInsertSort(e_Mode);

	void                 printBefore() const;
	void                 printAfter() const;
};

# include "PmergeMe.tpp"
