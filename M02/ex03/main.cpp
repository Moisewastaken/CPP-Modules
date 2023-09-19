#include "Point.hpp"
#include <iostream>

int main( void ) 
{
	if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(3, 2) ) == true ) {
        std::cout << "Point is in the triangle" << std::endl;
    } else {
        std::cout << "Point is not in the triangle" << std::endl;
    }
	return 0;
}