#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		try
		{
			// Span	sp;
			Span	sp(4);

			// sp.addNumber(1);
			// std::cout << sp.shortestSpan() << std::endl;
			sp.addNumber(2);
			sp.addNumber(45);
			std::cout << sp.shortestSpan() << std::endl;
			sp.addNumber(12);
			sp.addNumber(65987321);
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch( std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			srand(time(NULL));
			std::vector<int> lst(50000);
			std::generate(lst.begin(), lst.end(), std::rand);
			Span	span(20000);

			span.addNumbers(lst.begin(), lst.end());
			std::cout << span.shortestSpan() << std::endl;
			std::cout << span.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}