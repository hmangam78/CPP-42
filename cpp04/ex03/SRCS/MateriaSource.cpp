/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:46:53 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/08 15:29:24 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include "../includes/macros.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_known[i] = NULL;
	if (SHOWALL)
		std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._known[i] != NULL)
			this->_known[i] = other._known[i];
		else
			this->_known[i] = NULL;
	}
	if (SHOWALL)
		std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (SHOWALL)
		std::cout << "MateriaSource assignment called" << std::endl;
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->_known[i] != NULL)
			delete this->_known[i];
		this->_known[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		if (other._known[i] != NULL)
			this->_known[i] = other._known[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_known[i] != NULL)
			delete this->_known[i];
	}
	if (SHOWALL)
		std::cout << "MateriaSource destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* other)
{
	if (!other)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_known[i] == NULL)
		{
			this->_known[i] = other;
			return ;
		}
	}
	std::cout << "Can't learn a new Materia, slots full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_known[i] && (this->_known[i]->getType() == type))
		{
			AMateria* new_materia = this->_known[i]->clone();
			return new_materia;
		}
	}
	std::cout << "Materia " << type << " unknown, can't create" << std::endl;
	return (0);
}
AMateria* MateriaSource::getMateria(int idx) const
{
	if ((idx < 0) || (idx > 3))
	{
		std::cout << "Index out of range" << std::endl;
		return NULL;
	}
	if (this->_known[idx] != NULL)
		return this->_known[idx];
	else
		return NULL;
}
