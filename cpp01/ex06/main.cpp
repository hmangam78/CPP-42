/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:11:30 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/03 10:43:58 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	getLog_Level(const std::string& level)
{
	if (level == "DEBUG") return 0;
	if (level == "INFO") return 1;
	if (level == "WARNING") return 2;
	if (level == "ERROR") return 3;
	return -1;
}

int	main(int args, char **argv)
{
	Harl	grumpy_customer;

	if (args != 2)
	{
		std::cout << "Usage: 'harlFilter <complain level>'" << std::endl;
		return (1);
	}
	std::string	level = std::string(argv[1]);
	int	levelValue = getLog_Level(level);
	switch (levelValue)
	{
		case DEBUG:
			grumpy_customer.complain("DEBUG");
			// fallthrough
		case INFO:
			grumpy_customer.complain("INFO");
			// fallthrough
		case WARNING:
			grumpy_customer.complain("WARNING");
			// fallthrough
		case ERROR:
			grumpy_customer.complain("ERROR");
			break;
		default:
			std::cout << "Old man yelling at clouds" << std::endl;
			break;
	}
	return (0);
}