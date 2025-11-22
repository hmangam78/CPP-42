/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:12:00 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/08 12:58:21 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/macros.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
	if (SHOWALL)
		std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(void) : _type(std::string())
{
	if (SHOWALL)
		std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	if (SHOWALL)
		std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (SHOWALL)
		std::cout << "AMateria assignment called" << std::endl;
	if (this == &other)
		return (*this);
	else
		this->_type = other._type;
	return (*this);
}

AMateria::~AMateria(void)
{
	if (SHOWALL)
		std::cout << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Wrong usage of AMateria on " << target.getName() << std::endl;
}
