#include "../include/BitcoinExchangeBis.hpp"

BitcoinExchangeBis::BitcoinExchangeBis() {};

BitcoinExchangeBis::~BitcoinExchangeBis()
{

};

BitcoinExchangeBis::BitcoinExchangeBis(const std::string& file1, const std::string& file2)
: _dataPath(file1),
  _inputPath(file2)
{
	_dataFile.open(_dataPath);
	_inputFile.open(_inputPath);

	if (!_dataFile.is_open() || !_inputFile.is_open())
		throw ErrorFile();
	
	addToContainer();
}

void	BitcoinExchangeBis::addToContainer()
{
	std::string line;
	while (std::getline(_dataFile, line))
	{
		std::stringstream iss(line);
		std::string key;
		std::string	value;

		if (std::getline(iss, key, ',') && std::getline(iss, value))
		{
			_data[key] = std::atof(value.c_str());
		}
	}
}

void	BitcoinExchangeBis::scanExchangeRate()
{
	std::string line;
	while (std::getline(_inputFile, line))
	{
		std::stringstream iss(line);
		std::string key;
		std::string	value;

		if (std::getline(iss, key, '|') && std::getline(iss, value))
		{
			double number = atof(value.c_str());
			if (!isOutOfRange(number, setType(number)))
				computeExchange(key, value);
		}
		else
			std::cout << "Error: bad input => " << value << std::endl;
	}
}

void	BitcoinExchangeBis::computeExchange(const std::string& key, const std::string& value) const
{
	double number = atof(value.c_str());
	e_Type type = setType(number);

	switch (type)
	{
		case FLOAT_TYPE:
			float nbr = static_cast<float>(number);
			nbr * getExchangeRate(key);
			break ;
		case INT_TYPE:
			;
			break ;
		default:
			;
	}
}


bool	BitcoinExchangeBis::isOutOfRange(double nbr) const
{
	if ((nbr < std::numeric_limits<float>::min()
		|| nbr > std::numeric_limits<float>::max()))
		return true;

	return false;
}

const char* BitcoinExchangeBis::ErrorFile::what() const throw()
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
