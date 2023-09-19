/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:28:40 by mcochin           #+#    #+#             */
/*   Updated: 2023/04/03 11:35:10 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
public:
	
	void	AddContact();
	void	SearchContact();
	PhoneBook();
	~PhoneBook();
	
private:
	void	DisplayContacts();
	
	Contact	contacts[8];
	int	index;
	int	contactNumber;
};

#endif

