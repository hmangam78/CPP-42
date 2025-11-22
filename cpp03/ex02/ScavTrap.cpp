/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:28:36 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/03 13:02:17 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment called" << std::endl;
	if (this == &other)
		return (*this);
	ClapTrap::operator=(other);
	return (*this);
}

void ScavTrap::guardGate()
{
	if (this->getName().length() > 0)
		std::cout << "ScavTrap " << this->getName()
				  << " is in Gate keeper mode" << std::endl;
	else
		std::cout << "Unnamed ScavTrap is in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() <= 0)
	{
		std::cout << "ScavTrap has no energy points left, can't attack" << std::endl;
		return ;
	}
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap is dead, can't attack" << std::endl;
		return ;
	}
	if (this->getName().length() > 0)
		std::cout << "ScavTrap " << this->getName()
				  << " attacks " << target << " dealing "
				  << this->getAttackDamage() << " points of damage" << std::endl;
	else
		std::cout << "Unnamed ScavTrap attacks " << target 
				  << " dealing " << this->getAttackDamage()
				  << " points of damage" << std::endl;
	this->_energypoints -= 1;
}