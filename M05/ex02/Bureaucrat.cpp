#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ): _name("Default"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat( std::string name, int grade): _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy): _name(copy._name)
{
	*this = copy;
}

Bureaucrat  &Bureaucrat::operator=( Bureaucrat const &rhs)
{
	if (this == &rhs)
		return *this;
	this->_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat( void )
{
	return ;
}

const int	&Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

const std::string	&Bureaucrat::getName( void ) const
{
	return this->_name;
}

void	Bureaucrat::incrementGrade( void )
{
	if ((this->_grade - 1) <= 0)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if ((this->_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm( AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &form)
	{
		std::cout << this->_name << " couldn't sign " << f.getName() << " because " << form.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (AForm::FormNotSignedException &sign)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because " << sign.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &sign)
	{
		std::cout << this->_name << " cannot execute " << form.getName() << " because " << sign.what() << std::endl;
	}
}

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::flush;
	return o;
}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return "Grade Too High";
}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return "Grade Too Low";
}