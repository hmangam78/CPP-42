/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombiehorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:03:44 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/01 16:06:53 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# ifndef HORDE_SIZE
#  define HORDE_SIZE 5
# endif
# include <iostream>
# include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

#endif