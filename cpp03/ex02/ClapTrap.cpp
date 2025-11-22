/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:00:26 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/03 12:44:46 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hitpoints(10), _energypoints(10),
					_attackdamage(0)
{
	std::cout << "Default ClapTrap constructor called" << " >> "
	          << "Unnamed ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10),
					_energypoints(10), _attackdamage(0)
{
	std::cout << "ClapTrap constructor called" << " >> "
	          << "Claptrapp " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	this->_name = other.getName();
	this->_hitpoints = other.getHitPoints();
	this->_energypoints = other.getEnergyPoints();
	this->_attackdamage = other.getAttackDamage();
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap destructor called" << " >> ";
	if (this->getName().length() > 0)
	    std::cout << this->_name << " destroyed" << std::endl;
	else
		std::cout << "Unnamed ClapTrap destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment called" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other.getName();
	this->_hitpoints = other.getHitPoints();
	this->_energypoints = other.getEnergyPoints();
	this->_attackdamage = other.getAttackDamage();
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if ((this->getEnergyPoints() > 0) && (this->getHitPoints() > 0))
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target
		          << ", causing " << this->getAttackDamage()
		          << " points of damage!" << std::endl;
		this->_energypoints -= 1;
	}
	else if (this->getEnergyPoints() <= 0)
	{
		std::cout << "ClapTrap " << this->getName()
		          << " has no energy points to make this attack!" << std::endl;
	}
	else if (this->getHitPoints() <= 0)
	{
		std::cout << "ClapTrap " << this->getName()
		          << " is dead, it cannot attack if it's dead..." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int ammount)
{
	this->_hitpoints -= ammount;
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ClapTrap " << this->getName()
				  << " is dead after receiving " << ammount
				  << " points of damage" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->getName() << " takes "
				  << ammount << " points of damage!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int ammount)
{
	if ((this->getEnergyPoints() > 0) && (this->getHitPoints() > 0))
	{
		this->_energypoints -= 1;
		this->_hitpoints += ammount;
		std::cout << "ClapTrap " << this->getName() << " recovered "
			      << ammount << " hit points" << " after repairing" << std::endl;
	}
	else if (this->getEnergyPoints() <= 0)
	{
		std::cout << this->getName() << " has no energy left to be repaired"
				  << std::endl;
	}
	else if (this->getHitPoints() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is dead, it cannot "
				  << "repair itself if it's dead..." << std::endl;
	}
}

int		ClapTrap::getHitPoints(void) const
{
	return (this->_hitpoints);
}

int		ClapTrap::getEnergyPoints(void) const
{
	return (this->_energypoints);
}

int		ClapTrap::getAttackDamage(void) const
{
	return (this->_attackdamage);
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}