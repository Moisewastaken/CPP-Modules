#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>

class	AForm;

class Bureaucrat
{
	private :
		std::string	const _name;
		int	_grade;
		Bureaucrat( void );
	public :
		Bureaucrat( std::string name, int grade);
		Bureaucrat( Bureaucrat const &copy );
		~Bureaucrat( void );
		Bureaucrat	&operator=( Bureaucrat const &rhs );

		const int			&getGrade( void ) const;
		const std::string	&getName( void ) const;

		void	incrementGrade( void );
		void	decrementGrade( void );
		void	signForm( AForm &f );
		void	executeForm(AForm const & form) const;


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

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &rhs);

#endif
