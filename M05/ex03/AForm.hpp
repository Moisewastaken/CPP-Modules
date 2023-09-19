#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class	Bureaucrat;

class AForm
{
	protected :
		std::string const _name;
		bool	_signed;
		int		const	_exexGrade;
		int		const	_signGrade;
		AForm( void );
	public :
		AForm( std::string name, int const execGrade, int const signGrade);
		AForm( AForm const &copy );
		virtual ~AForm( void );
		AForm	&operator=( AForm const &rhs );

		const bool			&getSign( void ) const;
		const int			&getExecGrade( void ) const;
		const int			&getSignGrade( void ) const;
		const std::string	&getName( void ) const;

		void	beSigned( Bureaucrat const &b );
		virtual void	execute(Bureaucrat const & executor) const = 0;


		class FormNotSignedException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};
};

std::ostream	&operator<<( std::ostream &o, AForm const &rhs );

#endif
