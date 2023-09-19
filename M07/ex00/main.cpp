#include "Whatever.hpp"
#include <iostream>

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;


	float	e = 42.12;
	float	f = -4.465987;

	std::cout << "f = " << f << std::endl << "e = " << e << std::endl;
	std::cout << "Max is " << max(e, f) << std::endl;
	std::cout << "Min is " << min(e, f) << std::endl;
	std::cout << "Swap" << std::endl;
	swap(e, f);
	std::cout << "f = " << f << std::endl << "e = " << e << std::endl;
	std::cout << "Max is " << max(e, f) << std::endl;
	std::cout << "Min is " << min(e, f) << std::endl;
	return 0;
}