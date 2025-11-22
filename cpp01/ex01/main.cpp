/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:59:52 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/01 16:13:23 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "zombieHorde.hpp"

int	main(void)
{
	Zombie*	horde;
	int		i;

	horde = zombieHorde(HORDE_SIZE, "Generic zombie");
	i = 0;
	while (i < HORDE_SIZE)
	{
		horde[i].announce();
		i++;
	}	
	delete[] horde;
	return (0);
}