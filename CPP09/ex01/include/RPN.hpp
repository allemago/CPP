#pragma once

# include <iostream>
# include <stack>
# include <exception>
# include <algorithm>
# include <sstream>

# define ERR_expr_EMPTY "Error: please use constructor with expr parameter"

class RPN
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string                 _expr;
	std::stack<int>     		_numbers;

	void	computeRPN();

/*****************
*     PUBLIC     *
*****************/
public:
//	============== Constructors / Destructors ===================

	RPN();
	RPN(const std::string&);
	RPN(const RPN&);
	~RPN();
	RPN&	operator=(const RPN&);
	
//	==================== Getters / Setters ======================

	int    getResult() const;
};
