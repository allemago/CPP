#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
                  : _dataFile(),
                    _inputFile() { init(); };

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const std::string& file1, const std::string& file2)
                  : _dataFile(file1.c_str()),
                    _inputFile(file2.c_str()) { init(); }

void	BitcoinExchange::init()
{
	if (!_dataFile.is_open() || !_inputFile.is_open())
		throw std::runtime_error(ERROR_OPEN_FILE);

	std::string line;
	while (getline(_dataFile, line))
	{
		std::stringstream iss(line);
		std::string key;
		std::string	value;

		if (getline(iss, key, ',') && getline(iss, value))
			_data[key] = atof(value.c_str());
	}

	_longMonths.push_back(JANUARY);
	_longMonths.push_back(MARCH);
	_longMonths.push_back(MAY);
	_longMonths.push_back(JULY);
	_longMonths.push_back(AUGUST);
	_longMonths.push_back(OCTOBER);
	_longMonths.push_back(DECEMBER);

	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	if (!now)
		throw std::runtime_error(ERROR_LOCAL_TIME);
	_currentYear = now->tm_year + 1900;
	_currentMonth = now->tm_mon + 1;
	_currentDay = now->tm_mday;
}

void	BitcoinExchange::convertBitcoinValue()
{
	std::string line;

	getline(_inputFile, line);
	if (line != FILE_FORMAT)
		throw std::runtime_error(ERROR_FILE_FORMAT);

	while (getline(_inputFile, line))
	{
		std::stringstream iss(line);
		std::string key;
		std::string	value;
		
		if (getline(iss, key, '|') && getline(iss, value) && isFormatValid(line, value))
		{
			if (isInRange(value))
				computeExchange(key, atof(value.c_str()));
		}
		else if (!line.empty())
			std::cout << BAD_INPUT << line << std::endl;
	}
}

bool	BitcoinExchange::isFormatValid(const std::string& line, const std::string& value) const
{
	size_t delim = line.find(" | ");
	size_t start = value.find_first_not_of(" ");

	if (delim == std::string::npos || start == std::string::npos || start != 1)
		return false;

	if (!isKeyValid(line.substr(0, delim)) || !isValueValid(value.substr(start)))
		return false;
	
	return true;
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	return ((year & 3) == 0 && (((year % 100) != 0) || ((year % 400) == 0)));
}

bool	BitcoinExchange::isKeyValid(const std::string& key) const
{
	if (key.size() != DATE_FORMAT_SIZE
		|| key[4] != '-' || key[7] != '-')
		return false;

	int	year = atoi((key.substr(0, 4).c_str()));
	int	month = atoi((key.substr(5, 2).c_str()));
	int	day = atoi((key.substr(8, 2).c_str()));

	if ((year == _currentYear && month > _currentMonth)
		|| (year == _currentYear && month == _currentMonth && day > _currentDay)
		|| year < 1900 || year > _currentYear || month < 1 || month > 12 || day < 1)
		return false;

	int maxDay;
	if (month == FEBRUARY)
	{
		isLeapYear(year) ? maxDay = 29 : maxDay = 28;
	}
	else
	{
		find(_longMonths.begin(), _longMonths.end(), month) != _longMonths.end() ?
			maxDay = 31 : maxDay = 30;
	}

	if (day > maxDay)
		return false;

	return true;
}

bool	BitcoinExchange::isValueValid(const std::string& value) const
{
	for (size_t i = 0; value[i]; i++)
	{
		if (!isdigit(value[i]) && std::string("-.").find(value[i]) == std::string::npos)
			return false;
	}

	std::istringstream iss(value);
	float	x;
	int		c;

	if (!(iss >> x) || iss >> c)
		return false;

	return true;
}

bool	BitcoinExchange::isInRange(const std::string& value) const
{
	float	nbr = atof(value.c_str());

	if (nbr < 0.0)
	{
		std::cout << NB_NOT_POSITIVE << std::endl;
		return false;
	}
	else if (nbr > 1000.0)
	{
		std::cout << NB_TOO_LARGE << std::endl;
		return false;
	}

	return true;
}

bool	BitcoinExchange::hasExchangeRate(const std::string& key, float& rate)
{
	std::map<const std::string, float>::iterator it = _data.find(key);

	if (it != _data.end())
	{
		rate = it->second;
		return true;
	}
	else
	{
		it = _data.upper_bound(key);
		if (it != _data.begin() && it != _data.end())
		{
			--it;
			rate = it->second;
			return true;
		}
	}

	return false;
}

void	BitcoinExchange::computeExchange(const std::string& key, const float nbr)
{
	float	rate = 0.0;
	
	if (hasExchangeRate(key, rate))
	{
		std::cout << key << "=> " << nbr << " = ";
		std::cout << nbr *  rate << std::endl;
	}
	else
		std::cout << NO_RATE_AVAILABLE << std::endl;
}
