/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcochin <mcochin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:21:46 by mcochin           #+#    #+#             */
/*   Updated: 2023/03/23 16:33:16 by mcochin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	z1 = Zombie("z1");
	Zombie	*z2 = newZombie("z2");
	
	z1.announce();
	z2->announce();
	randomChump("z3");
	delete z2;
	return (0);
}