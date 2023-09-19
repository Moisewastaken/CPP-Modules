#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class	Bureaucrat;

class Form
{
	private :
		std::string const _name;
		bool	_signed;
		int		const	_exexGrade;
		int		const	_signGrade;
		Form( void );
	public :
		Form( std::string name, int const execGrade, int const signGrade);
		Form( Form const &copy );
		~Form( void );
		Form	&operator=( Form const &rhs );

		const bool			&getSign( void ) const;
		const int			&getExecGrade( void ) const;
		const int			&getSignGrade( void ) const;
		const std::string	&getName( void ) const;
		void	beSigned( Bureaucrat const &b );

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

std::ostream	&operator<<( std::ostream &o, Form const &rhs );

#endif
