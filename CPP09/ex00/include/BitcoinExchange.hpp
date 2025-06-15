#pragma once

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <cctype>
# include <ctime>
# include <exception>
# include <stdexcept>

# define ERROR_LOCAL_TIME "Error: failed to get local time"
# define ERROR_OPEN_FILE "Error: could not open file(s)"
# define ERROR_FILE_FORMAT "Error: use correct format: date | value"
# define FILE_FORMAT "date | value"
# define DATE_FORMAT_SIZE 10
# define BAD_INPUT "Error: bad input => "
# define NO_RATE_AVAILABLE "Error: no price data available."
# define NB_NOT_POSITIVE "Error: not a positive number."
# define NB_TOO_LARGE "Error: too large a number."

enum	e_Months
{
	JANUARY = 1,
	FEBRUARY = 2,
	MARCH = 3,
	MAY = 5,
	JULY = 7,
	AUGUST = 8,
	OCTOBER = 10,
	DECEMBER = 12
};

class BitcoinExchange
{
/*****************
*    PRIVATE     *
*****************/
private:

	std::ifstream                   _dataFile;
	std::ifstream                   _inputFile;

	std::map<std::string, float>    _data;
	std::vector<int>				_longMonths;

	int                             _currentYear;
	int                             _currentMonth;
	int                             _currentDay;
	
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator=(const BitcoinExchange&);

//	==================== Private Methods ========================

	void    init();
	void    computeExchange(const std::string&, const float);
	bool    isFormatValid(const std::string&, const std::string&) const;
	bool    isKeyValid(const std::string&) const;
	bool    isValueValid(const std::string&) const;
	bool    isInRange(const std::string&) const;
	bool    isLeapYear(int) const;
	bool    hasExchangeRate(const std::string&, float&);

/*****************
*     PUBLIC     *
*****************/
public:
	
	BitcoinExchange();
	BitcoinExchange(const std::string&, const std::string&);
	~BitcoinExchange();

//	==================== Public Methods =========================

	void    convertBitcoinValue();
};
