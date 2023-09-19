#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
	return ;
}

ScalarConverter::ScalarConverter( ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter  &ScalarConverter::operator=( ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter( void )
{
	return ;
}

static bool	isNum( std::string const &literal)
{
	size_t	i = 0;

	if (literal.find_first_not_of("0123456789.+-f") != std::string::npos)
		return false;
	i = literal.find('f');
	if (i != std::string::npos && i != literal.size() - 1)
		return false;
	i = literal.find('.');
	if (i != std::string::npos && !(literal[i + 1] && literal[i - 1]))
		return false;
	if (literal.find('.', ++i) != std::string::npos)
		return false;
	if (literal.find('+', 1) != std::string::npos || literal.find('-', 1) != std::string::npos)
		return false;
	return true;
}

static void	printFloat( const std::string &literal )
{
	float	toFloat = std::strtof(literal.c_str(), NULL);
	long	toInt = static_cast<long>(toFloat);

	if (toInt > 127 || toInt < 0)
		std::cout << "Char: Impossible" << std::endl;
	else if (!std::isprint(toInt))
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: '" << (char)toInt << "'" << std::endl;
	if (toInt > INT_MAX || toInt < INT_MIN)
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << toInt << std::endl;
	if (toFloat > std::numeric_limits<float>::max())
	{
		std::cout << "Float: impossible" << std::endl;
		std::cout << "Double: impossible" << std::endl;
	}
	else
	{
		std::cout << "Float: " << toFloat << "f" << std::endl;
		std::cout << "Double: " << static_cast<double>(toFloat) << std::endl;
	}
}

static void	printDouble( const std::string &literal )
{
	long double	toDouble = std::strtold(literal.c_str(), NULL);
	long	toInt = static_cast<long>(toDouble);

	if (toInt > 127 || toInt < 0)
		std::cout << "Char: Impossible" << std::endl;
	else if (!std::isprint(toInt))
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: '" << (char)toInt << "'" << std::endl;
	if (toInt > INT_MAX || toInt < INT_MIN)
		std::cout << "Int: impossible" << std::endl;
	else
		std::cout << "Int: " << toInt << std::endl;
	if (toDouble > std::numeric_limits<double>::max())
	{
		std::cout << "Float: impossible" << std::endl;
		std::cout << "Double: impossible" << std::endl;
	}
	else
	{
		std::cout << "Float: " << static_cast<float>(toDouble) << "f" << std::endl;
		std::cout << "Double: " << toDouble << std::endl;
	}
}

static void	printInt( const std::string &literal )
{
	long	toInt = std::strtol(literal.c_str(), NULL, 10);

	if (toInt > INT_MAX || toInt < INT_MIN)
	{
		std::cerr << "Impossible conversion for type INT, number higher or lower than INT limits" << std::endl;
		return ;
	}
	if (toInt > 127 || toInt < 0)
		std::cout << "Char: Impossible" << std::endl;
	else if (!std::isprint(toInt))
		std::cout << "Char: Non displayable" << std::endl;
	else
		std::cout << "Char: '" << (char)toInt << "'" << std::endl;
	std::cout << "Int: " << toInt << std::endl;
	if (static_cast<double>(toInt) > std::numeric_limits<double>::max())
	{
		std::cout << "Float: impossible" << std::endl;
		std::cout << "Double: impossible" << std::endl;
	}
	else
	{
		std::cout << "Float: " << static_cast<float>((int)toInt) << ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>((int)toInt) << ".0" << std::endl;
	}
}

void	ScalarConverter::convert( std::string const &literal)
{
	if (isNum(literal))
	{
		if (literal.find('f') != std::string::npos)
			printFloat(literal);
		else if (literal.find('.') != std::string::npos)
			printDouble(literal);
		else
			printInt(literal);
	}
	else if (literal.length() == 1)
	{
		std::cout << "Char: \'" << literal[0] << "\'" << std::endl;
		std::cout << "Int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "Float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
		std::cout << "Double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
	}
	else
	{
		std::cout << "Char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
		if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
		{
			std::cout << "Float: " << std::numeric_limits<float>::infinity() << "f" << std::endl;
			std::cout << "Double: " << std::numeric_limits<double>::infinity() << std::endl;
		}
		else if (literal == "-inf" || literal == "-inff")
		{
			std::cout << "Float: " << -std::numeric_limits<float>::infinity() << "f" <<std::endl;
			std::cout << "Double: " << -std::numeric_limits<double>::infinity() << std::endl;
		}
		else if (literal == "nan" || literal == "nanf")
		{
			std::cout << "Float: " << std::numeric_limits<float>::quiet_NaN() << "f" <<std::endl;
			std::cout << "Double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
		}
		else
		{
			std::cout << "Float: impossible" << std::endl;
			std::cout << "Double: impossible" << std::endl;
		}
	}
}
