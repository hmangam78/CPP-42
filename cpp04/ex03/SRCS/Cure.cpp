/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:32:52 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/10 09:17:44 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/macros.hpp"

Cure::Cure(void) : AMateria("cure")
{
	if (SHOWALL)
		std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	if (SHOWALL)
		std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	if (SHOWALL)
		std::cout << "Cure assignment called" << std::endl;
	if (this == &other)
		return (*this);
	else
		this->_type = other._type;
	return (*this);
}

Cure::~Cure(void)
{
	if (SHOWALL)
		std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone(void) const
{
	Cure* new_cure = new Cure();
	if (SHOWALL)
		std::cout << "Cloning cure" << std::endl;
	return (new_cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
