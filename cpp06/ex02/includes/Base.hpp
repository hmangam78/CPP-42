/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:51:23 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/22 14:38:54 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

class Base
{
	public:
		virtual ~Base();
};
Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
	