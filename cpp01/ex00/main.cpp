/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:59:52 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/01 16:01:20 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie1;
	Zombie	zombie2;

	zombie1 = newZombie("Antonio");
	randomChump("Paco");
	zombie1->announce();
	delete zombie1;
	return (0);
}