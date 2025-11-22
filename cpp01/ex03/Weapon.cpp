/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:37:03 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/03 10:28:26 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	std::cout << "Weapon '" << name << "' created." << std::endl;
	type = name;
}

Weapon::~Weapon()
{
	std::cout << this->get_Type() << " destroyed" << std::endl;
}

const std::string&	Weapon::get_Type(void) const
{
	return (this->type);
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}