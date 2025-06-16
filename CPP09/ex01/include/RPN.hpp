#pragma once

# include <iostream>
# include <stack>
# include <exception>
# include <algorithm>
# include <sstream>

# define ERR_DEFCONST "Error: please use constructor with expression parameter"
# define ERR_EXPFORMAT "Error: please only use operator(s) and number(s) between 0 and 10"

class RPN
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string                 _expression;
	std::stack<int>     		_numbers;

	bool    isExpressionValid();
	void	init();

/*****************
*     PUBLIC     *
*****************/
public:
//	==================== Canonical Form =========================

	RPN();
	RPN(const std::string&);
	RPN(const RPN&);
	~RPN();
	RPN&	operator=(const RPN&);

//	==================== Custom Constructors ====================
//	==================== Getters / Setters ======================
//	==================== Public Methods =========================

	void    computeExpression();

//	==================== Exceptions =============================
};
