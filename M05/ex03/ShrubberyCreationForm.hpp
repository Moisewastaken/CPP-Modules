#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm: public AForm
{
	private :
		std::string	const _target;
		ShrubberyCreationForm( void );
	public :
		ShrubberyCreationForm( std::string const &target);
		ShrubberyCreationForm( ShrubberyCreationForm const &copy );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm	&operator=( ShrubberyCreationForm const &rhs );

		void	execute(Bureaucrat const & executor) const;
};

#endif
