#pragma once

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>
# include <vector>
# include <map>
# include <algorithm>
# include <iterator>
# include <cstdlib>
# include <cfloat>
# include <limits>

class BitcoinExchangeBis
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string						_dataPath;
	std::string						_inputPath;

	std::ifstream					_dataFile;
	std::ifstream					_inputFile;

	std::map<std::string, float>	_data;
	
	BitcoinExchangeBis(const BitcoinExchangeBis&);
	BitcoinExchangeBis& operator=(const BitcoinExchangeBis&);
	
/*****************
*     PUBLIC     *
*****************/
public:
	
	BitcoinExchangeBis();
	~BitcoinExchangeBis();
	BitcoinExchangeBis(const std::string&, const std::string&);

//	==================== Public Methods =========================

	void	addToContainer();
	void	scanExchangeRate();

	bool	isOutOfRange(double) const;

	template < typename T >
	void	BitcoinExchangeBis::computeExchange(const std::string& key, const std::string& value) const
	{
		double number = atof(value.c_str());
		T nbr = setType(number);

		switch (type)
		{
			case FLOAT_TYPE:
				nbr * getExchangeRate(key);
				break ;
			case INT_TYPE:
				;
				break ;
			default:
				;
		}
	}

	const T&	BitcoinExchangeBis::setType(const float number) const
	{
		if ((number < std::numeric_limits<float>::min()
			|| number > std::numeric_limits<float>::max()))
		{
			std::cout << "Error: float value out of range." << std::endl;
			return 0;	
		}
	}

	template < typename T >
	const T& getExchangeRate(const std::string& key)
	{

	}	

//	==================== Exceptions =============================

	class ErrorFile : public std::exception
	{
		public:
			const char* what() const throw();
	};

};
