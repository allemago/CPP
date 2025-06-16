#pragma once

# include <iostream>
# include <stack>
# include <exception>
# include <algorithm>
# include <sstream>

# define ERR_OPERAND "Error: not enough operands"
# define ERR_DIV_ZERO "Error: division by zero"

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
