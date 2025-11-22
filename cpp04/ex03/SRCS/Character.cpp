/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:46:21 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/08 15:33:43 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/macros.hpp"

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	if (SHOWALL)
		std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
	}
	if (SHOWALL)
		std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if (SHOWALL)
		std::cout << "Character assignment called" << std::endl;
	if (this == &other)
		return (*this);
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	if (SHOWALL)
		std::cout << "Character destructor called" << std::endl;
}

std::string const& Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
		i++;
	}
	std::cout << "Inventory full, can't equip" << std::endl;
}
void Character::unequip(int idx)
{
	if ((idx < 0) || (idx > 3))
		return ;
	if (this->_inventory[idx] != NULL)
	{
		this->_inventory[idx] = NULL;
		std::cout << this->getName() << " dropped an item" << std::endl;
	}
	else
		std::cout << "Tried to unequip an empty slot" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx < 0) || (idx > 3))
	{
		std::cout << "Index out of range" << std::endl;
		return ;
	}
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
	else
		std::cout << "Tried to use an item from an empty slot" << std::endl;
}

AMateria* Character::handOutMateria(int idx)
{
	if ((idx < 0) || (idx > 3))
	{
		std::cout << "Index out of range" << std::endl;
		return NULL;
	}
	else if (this->_inventory[idx] == NULL)
	{
		std::cout << "Empty slot selected" << std::endl;
		return NULL;
	}
	return (this->_inventory[idx]);
}
