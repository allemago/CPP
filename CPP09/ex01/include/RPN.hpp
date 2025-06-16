#pragma once

# include <iostream>
# include <stack>
# include <exception>
# include <algorithm>
# include <sstream>

# define ERR_DEFCONST "Error: please use constructor with expression parameter"

class RPN
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string                 _expression;
	std::stack<int>     		_numbers;

	void	init();

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
