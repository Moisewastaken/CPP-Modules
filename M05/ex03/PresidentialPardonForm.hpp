#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm: public AForm
{
	private :
		std::string	const _target;
		PresidentialPardonForm( void );
	public :
		PresidentialPardonForm( std::string const &target);
		PresidentialPardonForm( PresidentialPardonForm const &copy );
		~PresidentialPardonForm( void );
		PresidentialPardonForm	&operator=( PresidentialPardonForm const &rhs );

		void	execute(Bureaucrat const & executor) const;
};

#endif
