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
# include <ctime>
# include <cmath>

# define USAGE "Usage: ./PmergeMe [positive integer sequence]"
# define MAX_SIZE_REACHED "Maximum of 4000 integers has been reached"
# define WHITESPACE "\t\n\v\f\r "
# define DEQUE_TYPE 1
# define VECTOR_TYPE 2
# define MAX_SIZE 4000
# define MICRO_SEC 1000000

extern time_t g_startTime;

class PmergeMe
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string                          _rawSequence;

	std::deque<int>                      _d;
	std::vector< std::pair<int, int> >   _v;

//	==================== Private Methods ========================

	void	init();
	void    parseSequence();
	void    printBefore() const;
	void	mergeInsert();

/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Canonical Form =========================

	PmergeMe();
	PmergeMe(const PmergeMe&);
	~PmergeMe();
	PmergeMe&	operator=(const PmergeMe&);
	
//	==================== Custom Constructors ====================

	PmergeMe(const std::string&);

//	==================== Getters / Setters ======================

	const std::deque<int>&                      getD() const;
	const std::vector< std::pair<int, int> >&   getV() const;
	float                                       getTime() const;

//	==================== Public Methods =========================

	void	process();

};

std::ostream&	operator<<(std::ostream&, const PmergeMe&);
