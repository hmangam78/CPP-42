/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:10:07 by hgamiz-g          #+#    #+#             */
/*   Updated: 2026/01/14 23:18:30 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btc.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong usage: use './btc <inputfile>'" << std::endl;
		return (1);
	}
	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Error: couldn't open file" << std::endl;
		return (1);
	}
	std::map<long, float>	database;
	if (parse_database(database))
		return (1);
	
	btc(database, input);
	return 0;
}