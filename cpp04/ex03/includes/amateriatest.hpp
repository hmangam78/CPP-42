/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:26:21 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/08 12:57:46 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/MateriaSource.hpp"
#include "../includes/Character.hpp"

void	subject_main(void);
void	add_to_dropped(AMateria** dropped, AMateria* newitem);
void	dropItem(AMateria **dropped, ICharacter* character, int idx);
void	run_tests(void);
