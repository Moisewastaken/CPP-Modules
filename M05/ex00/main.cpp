#include "Bureaucrat.hpp"

int	main( void )
{
	try
	{
		Bureaucrat test("test", 2);
		std::cout << test << std::endl;
		test.incrementGrade();
		std::cout << test << std::endl;
		test.incrementGrade();
	}
	catch( Bureaucrat::GradeTooHighException &exep)
	{
		std::cout << exep.what() << std::endl;
	}
	try
	{
		Bureaucrat test1("test1", 150);
		std::cout << test1 << std::endl;
		test1.decrementGrade();
	}
	catch( Bureaucrat::GradeTooLowException &exep)
	{
		std::cout << exep.what() << std::endl;
	}
}