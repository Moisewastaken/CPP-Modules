#include "Form.hpp"

Form::Form( void ): _name("Default"), _signed(false), _exexGrade(150), _signGrade(150) 
{
	return ;
}

Form::Form( std::string name, int const execGrade, int const signGrade):
		_name(name), _signed(false), _exexGrade(execGrade), _signGrade(signGrade)
{
	if (execGrade > 150 || signGrade > 150)
		throw Form::GradeTooLowException();
	if (execGrade <= 0 || signGrade <= 0)
		throw Form::GradeTooHighException();
	return ;
}

Form::Form( Form const &copy ):
	_name(copy.getName()), _exexGrade(copy.getExecGrade()), _signGrade(copy.getSignGrade())
{
	*this = copy;
}

Form  &Form::operator=( Form const &rhs )
{
	if (this == &rhs)
		return *this;
	this->_signed = rhs.getSign();
	return *this;
}

Form::~Form( void )
{
	return ;
}

const bool	&Form::getSign( void ) const
{
	return this->_signed;
}

const int		&Form::getExecGrade( void ) const
{
	return this->_exexGrade;
}

const int		&Form::getSignGrade( void ) const
{
	return this->_signGrade;
}

const std::string	&Form::getName( void ) const
{
	return this->_name;
}

std::ostream	&operator<<( std::ostream &o, const Form &rhs)
{
	o << "Form's Name :" << rhs.getName() << std::endl;
	o << "Form's Sign Grade :" << rhs.getSignGrade() << std::endl;
	o << "Form's Execution Grade :" << rhs.getExecGrade() << std::endl;
	o << "Is signed :" << rhs.getSign() << std::endl;
	return o;
}

void	Form::beSigned( Bureaucrat const &b)
{
	if (b.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char	*Form::GradeTooHighException::what( void ) const throw()
{
	return "Grade Too High";
}

const char	*Form::GradeTooLowException::what( void ) const throw()
{
	return "Grade Too Low";
}

