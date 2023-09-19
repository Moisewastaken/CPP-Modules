/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:21:40 by mcochin           #+#    #+#             */
/*   Updated: 2023/04/03 11:36:45 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phone_book;
	std::string	str;

	std::cout << "Type ADD to add a new contact to your PhoneBook" << std::endl;
	std::cout << "Type SEARCH to see all your contacts" << std::endl;
	std::cout << "Type EXIT to erase your PhoneBook and leave the program" << std::endl;
	do
	{
		std::cin >> str;
		if (str == "ADD")
			phone_book.AddContact();
		if (str == "SEARCH")
			phone_book.SearchContact();
		std::cin.clear();
	} while (str != "EXIT");
}