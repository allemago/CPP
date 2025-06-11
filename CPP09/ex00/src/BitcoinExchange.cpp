#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::~BitcoinExchange()
{

};

BitcoinExchange::BitcoinExchange(const std::string& file1, const std::string& file2)
: _dataPath(file1),
  _inputPath(file2)
{
	_data.open(_dataPath);
	_input.open(_inputPath);

	if (!_data.is_open() || !_input.is_open())
		throw ErrorFile();
	
	addToContainer();
}

void	BitcoinExchange::addToContainer()
{
	std::string line;
	while (std::getline(_input, line))
		_dataToEvaluate.push_back(line);
}

void	BitcoinExchange::scanExchangeRate() const
{

}

void	BitcoinExchange::computeExchange() const
{
	
}

void	BitcoinExchange::checkRange() const
{
	
}

const char* BitcoinExchange::ErrorFile::what() const throw()
{
	return "Error: could not open file.";
}


/* std::string line;
while (std::getline(_inputFile, line))
{
	std::stringstream iss(line);
	std::string key;
	std::string value;

	if (std::getline(iss, key, '|') && std::getline(iss, value))
	{
		_data[key] = value;
	}
}
 */
