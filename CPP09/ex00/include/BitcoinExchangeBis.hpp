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

enum	e_Type
{
	INVALID_TYPE = 0,
	FLOAT_TYPE = 1,
	INT_TYPE = 2
};

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
	void	computeExchange(const std::string&, const std::string&) const;
	bool	isOutOfRange(const float) const;
	e_Type	setType(const float) const;

//	==================== Exceptions =============================

	class ErrorFile : public std::exception
	{
		public:
			const char* what() const throw();
	};

};
