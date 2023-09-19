#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string const &target ): AForm(target, 45, 72), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &copy): AForm(copy), _target(copy._target)
{
	*this = copy;
}

RobotomyRequestForm  &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs)
{
	(void)rhs;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	return ;
}

void	RobotomyRequestForm::execute( Bureaucrat const &executor) const
{
	static	int	i;

	if (!this->getSign())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

	std::cout << "*BRRRRRRRRRR*" << std::endl;
	if (i % 2 == 0)
		std::cout << this->_target << "has been Robotomized succesfully !" << std::endl;
	else
		std::cout << "Robotomization failed on " << this->_target << " !" << std::endl;
	i++;
}
