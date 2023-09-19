/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:31:00 by mcochin           #+#    #+#             */
/*   Updated: 2023/03/22 14:20:58 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	PhoneNumber;
	std::string	DarkestSecret;
	
public:
	void	SetFirstName(std::string FirstName);
	void	SetLastName(std::string LastName);
	void	SetNickName(std::string NickName);
	void	SetNumber(std::string Number);
	void	SetSecret(std::string Secret);
	void	PrintInfoGrid();
	void	PrintInfoLine();

	std::string	GetFirstName();
	std::string	GetLastName();
	std::string	GetNickName();
	std::string	GetNumber();
	std::string	GetSecret();
	
	Contact(void);
	~Contact(void);
};


