/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 22:09:49 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/26 10:20:32 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <sstream>

int	get_int(std::string str)
{
	size_t	i;
	int		result;

	i = 0;
	result = -1;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (result);
		i++;
	}
	std::stringstream ss(str);
	int num;
	ss >> num;
	return (num);
}

std::string	validate_entry(void)
{
	std::string	str;

	str = "";
	while (str.length() == 0)
	{
		std::getline(std::cin, str);
		if (str.length() == 0)
			std::cout << "Empty fields are not valid, please enter something: ";
		else
			return (str);
	}
	return (str);
}

void	display_line(void)
{
	std::cout << GREEN "<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>" RESET;
	std::cout << std::endl;
}
