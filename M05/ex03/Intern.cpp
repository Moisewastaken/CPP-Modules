#include "Intern.hpp"

Intern::Intern( void )
{
	return ;
}

Intern::Intern( Intern const &copy)
{
	*this = copy;
}

Intern  &Intern::operator=( Intern const &rhs)
{
	(void)rhs;
	return *this;
}

Intern::~Intern( void )
{
	return ;
}

static AForm	*getPres( std::string target )
{
	return (new PresidentialPardonForm( target ));
}

static AForm	*getShrubb( std::string target )
{
	return (new ShrubberyCreationForm( target ));
}

static AForm	*getRobot( std::string target )
{
	return (new RobotomyRequestForm( target ));
}

AForm	*Intern::makeForm( std::string name, std::string target)
{
	std::string	formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm		*(*forms[3])(std::string target) = {&getPres, &getShrubb, &getRobot};

	for(int i = 0;i < 3;i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Interns creates " << formNames[i] << std::endl;
			return (forms[i])(target);
		}
	}
	throw Intern::FormNotCreatedException();
	return NULL;
}

const char	*Intern::FormNotCreatedException::what( void ) const throw()
{
	return "Could not create form";
}
