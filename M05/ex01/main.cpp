#include "Bureaucrat.hpp"

int	main( void )
{
	try
	{
		Bureaucrat	Jim("Jim", 1);
		Bureaucrat	Bob("Bob", 130);
		// Bureaucrat	Oui("oui", -1);
		Form	beSure("beSure", 50, 50);
		// Form	notSure("notSure", -1, 0);

		std::cout << beSure << std::endl;
		Jim.signForm(beSure);
		Bob.signForm(beSure);
		std::cout << beSure << std::endl;
	}
	catch ( std::exception &exep)
	{
		std::cout << exep.what() << std::endl;
	}
}