#include "../include/RPN.hpp"

RPN::RPN()
{
	throw std::runtime_error(ERR_DEFCONST);
}

RPN::RPN(const std::string& expression) : _expression(expression)
{
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
		if (isdigit(token[0]) && token.size() == 1)
			_numbers.push(token[0] - '0');
		else if (token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
		{
			if (_numbers.size() < 2)
				throw std::runtime_error("Error: not enough operands");
			
			int b = _numbers.top();
			_numbers.pop();
			int a = _numbers.top();
			_numbers.pop();

			if (token == "+")
				_numbers.push(a + b);
			else if (token == "-")
				_numbers.push(a - b);
			else if (token == "*")
				_numbers.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Error: division by zero");
				_numbers.push(a / b);
			}
		}
		else
			throw std::runtime_error("Error");
		
	}

	if (_numbers.size() != 1)
		throw std::runtime_error("Error");
}

int	RPN::getResult() const
{
	return _numbers.top();
}
