/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:32:30 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/08 09:01:55 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/AMateria.hpp"

class	Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		virtual ~Ice(void);
		AMateria* clone(void) const;
		void use(ICharacter& target);
};
