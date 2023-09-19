#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string const &target ): AForm(target, 5, 25), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &copy): AForm(copy), _target(copy._target)
{
	*this = copy;
}

PresidentialPardonForm  &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs)
{
	(void)rhs;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	return ;
}

void	PresidentialPardonForm::execute( Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
