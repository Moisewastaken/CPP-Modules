#include "AForm.hpp"

AForm::AForm( void ): _name("Default"), _signed(false), _exexGrade(150), _signGrade(150) 
{
	return ;
}

AForm::AForm( std::string name, int const execGrade, int const signGrade):
		_name(name), _signed(false), _exexGrade(execGrade), _signGrade(signGrade)
{
	if (execGrade > 150 || signGrade > 150)
		throw AForm::GradeTooLowException();
	if (execGrade <= 0 || signGrade <= 0)
		throw AForm::GradeTooHighException();
	return ;
}

AForm::AForm( AForm const &copy ):
	_name(copy.getName()), _exexGrade(copy.getExecGrade()), _signGrade(copy.getSignGrade())
{
	*this = copy;
}

AForm  &AForm::operator=( AForm const &rhs )
{
	if (this == &rhs)
		return *this;
	this->_signed = rhs.getSign();
	return *this;
}

AForm::~AForm( void )
{
	return ;
}

const bool	&AForm::getSign( void ) const
{
	return this->_signed;
}

const int		&AForm::getExecGrade( void ) const
{
	return this->_exexGrade;
}

const int		&AForm::getSignGrade( void ) const
{
	return this->_signGrade;
}

const std::string	&AForm::getName( void ) const
{
	return this->_name;
}

std::ostream	&operator<<( std::ostream &o, const AForm &rhs)
{
	o << "Form's Name :" << rhs.getName() << std::endl;
	o << "Form's Sign Grade :" << rhs.getSignGrade() << std::endl;
	o << "Form's Execution Grade :" << rhs.getExecGrade() << std::endl;
	o << "Is signed :" << rhs.getSign() << std::endl;
	return o;
}

void	AForm::beSigned( Bureaucrat const &b)
{
	if (b.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char	*AForm::GradeTooHighException::what( void ) const throw()
{
	return "Grade Too High";
}

const char	*AForm::GradeTooLowException::what( void ) const throw()
{
	return "Grade Too Low";
}

const char	*AForm::FormNotSignedException::what( void ) const throw()
{
	return "Grade Too High";
}

