#include "../include/RPN.hpp"

RPN::RPN()
{
	throw std::runtime_error(ERR_DEFCONST);
}

RPN::RPN(const std::string& expression) : _expression(expression)
{
	if (!isExpressionValid())
		throw std::runtime_error(ERR_EXPFORMAT);

	init();
}

RPN::RPN(const RPN& object)
{
	*this = object;
}

RPN&	RPN::operator=(const RPN& object)
{
	if (this != &object)
	{
		_expression = object._expression;
		while (!_numbers.empty())
			_numbers.pop();
		_numbers = object._numbers;
	}
	return *this;
}

RPN::~RPN() {}

void	RPN::init()
{
	std::stringstream iss(_expression);
	std::string token;
	while (iss >> token)
	{
		if (isdigit(token[0] && token.size() == 1))
			_numbers.push(token[0] - '0');
		else if (std::string("+-*/").find(token[0]) != std::string::npos)
		{
			
		}
		else
			throw std::runtime_error(ERR_EXPFORMAT);
		
	}
}

void	RPN::computeExpression()
{

}
/* 
std::stack<int> s;
std::stringstream iss(_expression);
std::string token;

while (iss >> token)
{
    if (isdigit(token[0]) && token.size() == 1)
        s.push(token[0] - '0');
    else if (token == "+" || token == "-" || token == "*" || token == "/")
    {
        if (s.size() < 2)
            throw std::runtime_error("Not enough operands");

        int b = s.top(); s.pop();
        int a = s.top(); s.pop();

        if (token == "+") s.push(a + b);
        else if (token == "-") s.push(a - b);
        else if (token == "*") s.push(a * b);
        else if (token == "/")
        {
            if (b == 0) throw std::runtime_error("Division by zero");
            s.push(a / b);
        }
    }
    else
        throw std::runtime_error("Invalid token");
}

 */