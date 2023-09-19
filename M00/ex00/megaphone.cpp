/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:32:59 by mcochin           #+#    #+#             */
/*   Updated: 2023/04/06 17:39:59 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>


int	main(int argc, char **argv)
{
	std::string	str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for(int i = 1;i < argc;i++)
		for(size_t j = 0;j < strlen(argv[i]);j++)
			std::cout << char(toupper(argv[i][j])) << std::flush;
	std::cout << std::endl;
	return (0);
}