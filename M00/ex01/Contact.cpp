/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:31:24 by mcochin           #+#    #+#             */
/*   Updated: 2023/03/22 14:29:10 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::SetFirstName(std::string FirstName)
{
	this->FirstName = FirstName;	
}

void	Contact::SetLastName(std::string LastName)
{
	this->LastName = LastName;	
}

void	Contact::SetNickName(std::string NickName)
{
	this->NickName = NickName;	
}

void	Contact::SetNumber(std::string Number)
{
	this->PhoneNumber = Number;	
}

void	Contact::SetSecret(std::string Secret)
{
	this->DarkestSecret = Secret;	
}

std::string	Contact::GetFirstName()
{
	return (this->FirstName);
}

std::string	Contact::GetLastName()
{
	return (this->LastName);
}

std::string	Contact::GetNickName()
{
	return (this->NickName);
}

std::string	Contact::GetNumber()
{
	return (this->PhoneNumber);
}

std::string	Contact::GetSecret()
{
	return (this->DarkestSecret);
}

void	Contact::PrintInfoGrid()
{
	if (this->GetFirstName().length() > 10)
		std::cout << std::setw(10) << this->GetFirstName().substr(0, 9).append(".");
	else
		std::cout << std::setw(10) << this->GetFirstName();
	std::cout << "|";
	if (this->GetLastName().length() > 10)
		std::cout << std::setw(10) << this->GetLastName().substr(0, 9).append(".");
	else
		std::cout << std::setw(10) << this->GetLastName();
	std::cout << "|";
	if (this->GetNickName().length() > 10)
		std::cout << std::setw(10) << this->GetNickName().substr(0, 9).append(".");
	else
		std::cout << std::setw(10) << this->GetNickName();
	std::cout << "|";
}

void	Contact::PrintInfoLine()
{
	std::cout << "Contact's first name : " << std::flush;
	std::cout << this->GetFirstName() << std::endl;
	std::cout << "Contact's last name : " << std::flush;
	std::cout << this->GetLastName() << std::endl;
	std::cout << "Contact's nickname : " << std::flush;
	std::cout << this->GetNickName() << std::endl;
	std::cout << "Contact's number : " << std::flush;
	std::cout << this->GetNumber() << std::endl;
	std::cout << "Contact's darkest secret : " << std::flush;
	std::cout << this->GetSecret() << std::endl;
}

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}