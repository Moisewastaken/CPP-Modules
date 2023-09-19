#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
	private :
		std::string	const _target;
		RobotomyRequestForm( void );
	public :
		RobotomyRequestForm( std::string const &target);
		RobotomyRequestForm( RobotomyRequestForm const &copy );
		~RobotomyRequestForm( void );
		RobotomyRequestForm	&operator=( RobotomyRequestForm const &rhs );

		void	execute(Bureaucrat const & executor) const;
};

#endif
