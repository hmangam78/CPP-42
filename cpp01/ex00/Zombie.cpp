/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:54:03 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/01 16:00:02 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie " << this->_name << " created" << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << "Unnamed generic zombie created" << std::endl;
}

Zombie::~Zombie(void)
{
	if (this->_name.length() != 0)
		std::cout << "Zombie named " << this->_name << " destroyed" << std::endl;
	else
		std::cout << "Generic zombie destroyed" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}