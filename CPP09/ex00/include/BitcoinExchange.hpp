#pragma once

# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <map>
# include <algorithm>
# include <iterator>

class BitcoinExchange
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::string					_dataPath;
	std::string					_inputPath;

	std::ifstream				_data;
	std::ifstream				_input;

	std::vector<std::string>	_dataToEvaluate;
	
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator=(const BitcoinExchange&);
	
/*****************
*     PUBLIC     *
*****************/
public:
	
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const std::string&, const std::string&);

//	==================== Public Methods =========================

	void	addToContainer();
	void	scanExchangeRate() const;
	void	computeExchange() const;
	void	checkRange() const;

//	==================== Exceptions =============================

	class ErrorFile : public std::exception
	{
		public:
			const char* what() const throw();
	};

};

