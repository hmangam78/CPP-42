/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:12:54 by hgamiz-g          #+#    #+#             */
/*   Updated: 2026/01/14 23:19:52 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btc.hpp"

int	parse_database(std::map<long, float>& database)
{
	std::ifstream	datafile("data.csv");
	if (!datafile.is_open())
	{
		std::cout << "Error opening database" << std::endl;
		return (1);
	}

	std::string	line;
	std::getline(datafile, line);

	while (std::getline(datafile, line))
	{
		size_t	separator = line.find(',');
		if (separator == std::string::npos)
		{
			std::cout << "Error parsing database" << std::endl;
            continue ;
		}

		std::string	date = trim(line.substr(0, separator));
		std::string	value = trim(line.substr(separator + 1));

		if (!isValidDate(date))
		{
			std::cout << "Invalid date found in database" << std::endl;
			continue ;	
		}
        
        if (!isFloat(value))
        {
            std::cout << "Invalid float value in database" << std::endl;
            continue ;
        }
        
		database.insert(std::make_pair(dateToInt(date), strToFloat(value)));
	}
    
	datafile.close();
	return (0);
}

long	dateToInt(const std::string& date)
{
	size_t	first_dash = date.find('-', 0);
	size_t	second_dash = date.find('-', first_dash + 1);
	long	year = std::atol(date.substr(0, first_dash).c_str());
	int		month = std::atoi(date.substr(first_dash + 1, second_dash - first_dash - 1).c_str());
	int		day = std::atoi(date.substr(second_dash + 1).c_str());

	return ((year * 10000) + (month * 100) + day);
}

float	strToFloat(const std::string& value)
{
	return (std::atof(value.c_str()));
}