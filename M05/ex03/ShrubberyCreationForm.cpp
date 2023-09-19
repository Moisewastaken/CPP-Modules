#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ): AForm(target, 137, 145), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &copy): AForm(copy), _target(copy._target)
{
	*this = copy;
}

ShrubberyCreationForm  &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs)
{
	(void)rhs;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	return ;
}

void	ShrubberyCreationForm::execute( Bureaucrat const &executor) const
{
	std::string	fileName;
	if (!this->getSign())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	
	fileName = this->_target.c_str();
	std::ofstream	out(fileName.append("_shrubbery").c_str());
	out << "     ccee88oo" << std::endl;
	out << "  C8O8O8Q8PoOb o8oo" << std::endl;
	out << " dOB69QO8PdUOpugoO9bD" << std::endl;
	out << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
	out << "    6OuU  /p u gcoUodpP" << std::endl;
	out << "      \\\\//  /douUP" << std::endl;
	out << "        \\\\////" << std::endl;
	out << "         |||/\\" << std::endl;
	out << "         |||\\/" << std::endl;
	out << "         |||||" << std::endl;
	out << "        //||||\\" << std::endl;
	out.close();
}
