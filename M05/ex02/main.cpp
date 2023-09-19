#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main( void )
{
	try
	{
		Bureaucrat	Jim("Jim", 1);
		Bureaucrat	Bob("Bob", 130);
		// AForm	beSure("Form", 50, 50);
		PresidentialPardonForm	Pres("PresPardon");
		RobotomyRequestForm		Robot("Robot");
		ShrubberyCreationForm	Shrubb("Shrubb");

		std::cout << "------Presidential------" << std::endl;
		std::cout << Pres << std::endl;
		// Pres.execute(Bob);
		Bob.signForm(Pres);
		std::cout << Pres << std::endl;
		Jim.signForm(Pres);
		std::cout << Pres << std::endl;
		// Pres.execute(Bob);
		Pres.execute(Jim);

		std::cout << "------Robotomy------" << std::endl;
		std::cout << Robot << std::endl;
		Jim.signForm(Robot);
		Bob.executeForm(Robot);
		Jim.executeForm(Robot);
		std::cout << "------Shrubbery------" << std::endl;
		std::cout << Shrubb << std::endl;
		Jim.signForm(Shrubb);
		Jim.executeForm(Shrubb);
	}
	catch ( std::exception &exep)
	{
		std::cout << exep.what() << std::endl;
	}
}