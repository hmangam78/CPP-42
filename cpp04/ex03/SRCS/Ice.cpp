/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:32:46 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/08 12:58:43 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/macros.hpp"

Ice::Ice(void) : AMateria("ice")
{
	if (SHOWALL)
		std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	if (SHOWALL)
		std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	if (SHOWALL)
		std::cout << "Ice assignment called" << std::endl;
	if (this == &other)
		return (*this);
	else
		this->_type = other._type;
	return (*this);
}

Ice::~Ice(void)
{
	if (SHOWALL)
		std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone(void) const
{
	Ice* new_ice = new Ice();
	if (SHOWALL)
		std::cout << "Cloning ice" << std::endl;
	return (new_ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
