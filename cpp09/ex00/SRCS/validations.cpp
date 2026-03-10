/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:12:00 by hgamiz-g          #+#    #+#             */
/*   Updated: 2026/01/14 23:13:20 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btc.hpp"

bool	isValidDateFormat(const std::string& date)
{
	size_t	first_dash = date.find('-', 0);
	if (first_dash == std::string::npos || first_dash == 0)
		return (false);
	size_t	second_dash = date.find('-', first_dash + 1);
	if (second_dash == std::string::npos)
		return (false);
	if (date.substr(first_dash + 1, second_dash - first_dash - 1).size() != 2)
		return false;
	if (date.substr(second_dash + 1).size() != 2)
		return false;
	for (size_t i = 0; i < date.size(); i++)
	{
		if ((i == first_dash) || (i == second_dash))
		{
			continue;
		}
		else
		{
			if (!std::isdigit(date[i]))
				return (false);
		}
	}
	return (true);
}

bool	isValidDate(const std::string& date)
{
	if (!isValidDateFormat(date))
		return (false);
	size_t	first_dash = date.find('-', 0);
	size_t	second_dash = date.find('-', first_dash + 1);
	long	year = std::atol(date.substr(0, first_dash).c_str());
	if (year > INT_MAX)
		return (false);
	int	month = std::atoi(date.substr(first_dash + 1, second_dash - first_dash - 1).c_str());
	int	day = std::atoi(date.substr(second_dash + 1).c_str());
	if (month < 1 || month > 12)
		return (false);
	int	daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (leap)
		daysInMonth[1] = 29;
	if (day < 1 || day > daysInMonth[month - 1])
		return (false);
	return (true);
}

bool	isFloat(const std::string& value)
{
	if (value.empty())
		return (false);

    bool dotSeen = false;
	for (size_t i = 0; i < value.size(); i++)
	{
        if (value[i] == '.')
        {
            if (dotSeen)
                return (false);
            dotSeen = true;
        }
		else if (!std::isdigit(value[i]))
			return (false);
	}
	return (true);
}

std::string trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t");
    if (start == std::string::npos)
        return ("");
    size_t  end = s.find_last_not_of(" \t");
    return (s.substr(start, end - start + 1));
}