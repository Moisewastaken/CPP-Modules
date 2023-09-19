#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <algorithm>
#include <ctime>
#include <string>
#include <limits>

class BitcoinExchange
{
	private :
		std::deque<std::string>	_db;
		
		BitcoinExchange( void );
	public :
		BitcoinExchange( const std::string &dbInput);
		BitcoinExchange( BitcoinExchange const &copy );
		~BitcoinExchange( void );
		BitcoinExchange	&operator=( BitcoinExchange const &rhs );

		void	displayInfo( const std::string &inputFile);
};

#endif
