/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:41:19 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/08 12:13:34 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class 	Character : public ICharacter
{
	protected:
		std::string _name;
		AMateria*	_inventory[4];
	public:
		Character(std::string const & name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character(void);
		const std::string& getName(void) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria* handOutMateria(int idx);
};
