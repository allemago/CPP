#pragma once

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <algorithm>
# include <exception>
# include <sstream>
# include <limits>

# define USAGE "Usage: ./PmergeMe [positive integer sequence]"
# define WHITESPACE "\t\n\v\f\r "
# define DEQUE_TYPE 1
# define VECTOR_TYPE 2

class PmergeMe
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string        _rawSequence;

	std::deque<int>    _d;
	std::vector<int>   _v;

//	==================== Private Methods ========================

	void	init();
	bool    isSequenceValid();

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


//	==================== Public Methods =========================

};

std::ostream&	operator<<(std::ostream&, const PmergeMe&);
