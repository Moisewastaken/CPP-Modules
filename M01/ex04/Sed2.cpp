#include "Sed2.hpp"

Sed2::Sed2(std::string infile)
{
	this->infile = infile;
	this->outfile = infile + ".replace";
}

Sed2::~Sed2(void)
{

}

void	Sed2::replace(std::string s1, std::string s2)
{
	std::ifstream	in(this->infile.c_str(), std::ifstream::in);
	std::string		line;
	size_t			pos;

	if (in.is_open())
	{
		if (std::getline(in, line, '\0'))
		{
			std::ofstream	out(this->outfile.c_str(), std::ofstream::out | std::ofstream::trunc);
			pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos)
			{
				line.erase(pos, s1.length());
				line.insert(pos, s2);
			}
			out << line;
			out.close();
			in.close();
		}
		else
		{
			std::cerr << "Error: empty file" << std::endl;
			in.close();
		}
	}
	else
	{
		std::cerr << "Error: can't open file" << std::endl;
		in.close();
	}
}