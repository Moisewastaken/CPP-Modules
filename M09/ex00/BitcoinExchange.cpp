#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
	return ;
}

BitcoinExchange::BitcoinExchange( const std::string &dbInput)
{
	std::ifstream	infile;
	std::string		line;

	infile.open(dbInput.c_str());
	if (infile.is_open())
	{
		while (std::getline(infile, line))
			this->_db.push_back(line);
	}
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &copy)
{
	*this = copy;
}

BitcoinExchange  &BitcoinExchange::operator=( BitcoinExchange const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_db = std::deque<std::string>(rhs._db);
	return *this;
}

BitcoinExchange::~BitcoinExchange( void )
{
	return ;
}

static bool isLeap(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

static bool	isValidDate( const std::string &date)
{
	struct tm	tm;
	char	*str = strptime(date.c_str(), "%Y-%m-%d", &tm);

	if (!str || *str != '\0')
	{
		std::cout << "oui" << std::endl;
		return false;
	}
	if (tm.tm_year + 1900 > 2050 || tm.tm_year + 1900 < 2009)
		return false;
	if (tm.tm_mon == 1 && isLeap(tm.tm_year))
		return (tm.tm_mday <= 29);
	if (tm.tm_mon == 1 && !isLeap(tm.tm_year))
		return (tm.tm_mday <= 28);
	if (tm.tm_mon == 3 || tm.tm_mon == 5 || tm.tm_mon == 8 || tm.tm_mon == 10)
		return (tm.tm_mday <= 30);
	return true;
}

static bool	parseLine( const std::string &line, const std::string &date, const std::string &sValue )
{
	size_t	pPos = line.find('|');
	if (date.find_first_not_of("0123456789-") != std::string::npos
		|| sValue.find_first_not_of("0123456789.-") != std::string::npos
		|| !isValidDate(date)
		|| pPos == std::string::npos || line[pPos - 1] != ' ' || line[pPos + 1] != ' ')
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	double	value = std::strtod(sValue.c_str(), NULL);
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large number." << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::displayInfo( const std::string &inputFile)
{
	std::ifstream	infile;
	std::string		line;

	infile.open(inputFile.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: can't open file" << std::endl;
		return ;
	}
	std::getline(infile, line);
	if (this->_db.empty())
	{
		std::cerr << "Error: database empty" << std::endl;
		return ;
	}
	if (line != "date | value")
	{
		std::cerr << "Error: bad input file format wanted 'date | value'" << std::endl;
		return ;
	}
	while (std::getline(infile, line))
	{
		if (line.empty())
			return ;
		std::string	date = line.substr(0, line.find('|') - 1);
		std::string	sValue = line.substr(line.find('|') + 2, line.length());
		if (parseLine(line, date, sValue))
		{
			double	value = std::strtod(line.substr(line.find('|') + 1, line.length()).c_str(), NULL);
			std::deque<std::string>::iterator it = std::lower_bound(this->_db.begin(), this->_db.end(), date);
			std::string	dbLine = *it;
			if (it == this->_db.begin())
				dbLine = *++it;
			else if (dbLine.substr(0, dbLine.find(',')) != date && it != this->_db.begin())
				dbLine = *--it;
			double	dbValue = std::strtod(dbLine.substr(dbLine.find(',') + 1, dbLine.length()).c_str(), NULL);
			std::cout << date << " => " << value << " = " << value * dbValue << std::endl;
		}
	}
}