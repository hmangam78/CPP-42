/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:37:40 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/03 10:20:00 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	std::cout << "HumanB " << name << " created" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->name << " destroyed" << std::endl;
}

void	HumanB::attack(void)
{
	if (this->weapon != NULL)
	{
		std::cout << this->name << " attacks with their ";
		std::cout << this->weapon->get_Type() << std::endl;
	}
	else
		std::cout << this->name << " is unarmed, can't attack." << std::endl;
}

void	HumanB::setWeapon(Weapon& weaponPTR)
{
	this->weapon = &weaponPTR;
}