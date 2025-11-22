/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:47:22 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/01 15:57:56 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	void	announce(void);
	void	set_name(std::string new_name);	
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif