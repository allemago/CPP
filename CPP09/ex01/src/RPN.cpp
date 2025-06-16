#include "../include/RPN.hpp"

RPN::RPN() { computeRPN(); }

RPN::RPN(const std::string& expr) : _expr(expr) { computeRPN(); }

RPN::RPN(const RPN& object) { *this = object; }

RPN&	RPN::operator=(const RPN& object)
{
	if (this != &object)
	{
		_expr = object._expr;
		while (!_numbers.empty())
			_numbers.pop();
		_numbers = object._numbers;
	}
	return *this;
}

RPN::~RPN() {}

void	RPN::computeRPN()
{
	if (!_expr.empty())
	{	
		std::stringstream iss(_expr);
		std::string token;
		while (iss >> token)
		{
			if (isdigit(token[0]) && token.size() == 1)
				_numbers.push(token[0] - '0');
			else if (token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos)
			{
				if (_numbers.size() < 2)
					throw std::runtime_error(ERR_OPERAND);
				
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
						throw std::runtime_error(ERR_DIV_ZERO);
					_numbers.push(a / b);
				}
			}
			else
				throw std::runtime_error("Error");
			
		}
	}

	if (_numbers.size() != 1)
		throw std::runtime_error("Error");
}

int	RPN::getResult() const
{
	return _numbers.top();
}
