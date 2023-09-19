#ifndef SED2_HPP
#define SED2_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Sed2
{
private:
	std::string	infile;
	std::string	outfile;
public:
	void	replace( std::string s1, std::string s2 );

	Sed2(std::string infile);
	~Sed2();
};

#endif
