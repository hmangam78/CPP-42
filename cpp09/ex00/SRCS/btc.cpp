/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:18:16 by hgamiz-g          #+#    #+#             */
/*   Updated: 2026/01/14 23:19:53 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btc.hpp"

void	displayDate(long date)
{
	int	day = date % 100;
	int month = (date % 10000) / 100;
	long year = (date / 10000);
	std::cout << year << '-'
			 << std::setw(2) << std::setfill('0') << month << '-'
			 << std::setw(2) << std::setfill('0') << day;
}

void	db_match(std::string& date, float f_value, std::map<long, float>& database)
{
	long	inputDate = dateToInt(date);
	std::map<long, float>::iterator it = database.lower_bound(inputDate);

	if (it == database.end() || it->first > inputDate)
	{
		if (it == database.begin())
		{
			std::cout << "Error: no data available for ";
			displayDate(inputDate);
			std::cout << std::endl;
			return ;
		}
		--it;
	}

	float btcValue = it->second;

	displayDate(inputDate);
	std::cout << " => " << btcValue * f_value << std::endl;
}

bool	parseInputLine(const std::string& line, std::string& date, float& f_value)
{
	size_t	separator = line.find('|');
	
	if (separator == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}
	
	date = trim(line.substr(0, separator));
	std::string value = trim(line.substr(separator + 1));

	if (!isValidDate(date))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}

	if (!isFloat(value))
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	
	f_value = strToFloat(value);
	if (f_value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	
	if (f_value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return (true);
}

void	btc(std::map<long, float>& database, std::ifstream& input)
{
	std::string	line, date;
	float		f_value;
	
	std::getline(input, line);
	while (std::getline(input, line))
	{
		if (!parseInputLine(line, date, f_value))
			continue;	
		db_match(date, f_value, database);
	}
}