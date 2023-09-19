/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:31:38 by mcochin           #+#    #+#             */
/*   Updated: 2023/04/06 15:15:53 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->contactNumber = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::AddContact()
{
	std::string	in;

	if (this->index == 8)
		this->index = 0;
	std::cout << "Enter your First Name : ";
	std::cin >> in; this->contacts[this->index].SetFirstName(in);
	std::cout << "Enter your Last Name : ";
	std::cin >> in; this->contacts[this->index].SetLastName(in);
	std::cout << "Enter your NickName : ";
	std::cin >> in; this->contacts[this->index].SetNickName(in);
	std::cout << "Enter your Number : ";
	std::cin >> in; this->contacts[this->index].SetNumber(in);
	std::cout << "Enter your Darkest Secret : ";
	std::cin >> in; this->contacts[this->index].SetSecret(in);
	std::cout << "Contact added !" << std::endl;
	if (this->contactNumber < 8)
		this->contactNumber++;
	this->index++;
}

void	PhoneBook::DisplayContacts()
{
	std::string	in;

	std::cout << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::setw(10) << "FirstName";
	std::cout << "|";
	std::cout << std::setw(10) << "LastName";
	std::cout << "|";
	std::cout << std::setw(10) << "NickName";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for(int i = 0;i < 8;i++)
	{
		std::cout << std::setw(10);
		std::cout << i + 1 << "|";
		this->contacts[i].PrintInfoGrid();
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl << std::endl;
}

void	PhoneBook::SearchContact()
{
	std::string	in;

	if (this->contactNumber == 0)
	{
		std::cout << "No contacts stored" << std::endl;
		return ;
	}
	this->DisplayContacts();
	while (1)
	{
		std::cout << "Enter contact index : " << std::flush;
		std::cin >> in;
		if (in.length() == 1 && in[0] > '0' && (in[0] - '0') <= this->contactNumber)
			break ;
		else
			std::cout << "Please, enter a valid contact index" << std::endl;
	}
	this->contacts[(in[0] - '0') - 1].PrintInfoLine();
}