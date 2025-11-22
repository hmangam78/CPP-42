/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:37:20 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/03 10:19:12 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weaponREF) :
	name(name), weapon(weaponREF)
{
	std::cout << "HumanA " << name << " created" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this->name << " destroyed" << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon.get_Type() << std::endl;
}