/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:04:29 by hgamiz-g          #+#    #+#             */
/*   Updated: 2026/03/10 16:40:17 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ========================== VALIDATION FUNCTIONS ======================== */

bool    valid_sequence(const char **argv)
{
    for (int i = 1; argv[i] != NULL; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            if (isspace(argv[i][j]))
                continue;
            if (!isdigit(argv[i][j]))
                return (false);
        }
    }
    return (true);
}

bool    is_valid_int(const std::string& token)
{
    char    *endptr;
    long    value = std::strtol(token.c_str(), &endptr, 10);

    if (*endptr != '\0')
        return (false);
    if (value > INT_MAX)
        return (false);
    return (true);
}

bool    read_sequence(const char **argv, std::vector<int>& input_sequence)
{
    std::string token;

    for (int i = 1; argv[i] != NULL; i++)
    {
        std::istringstream  iss(argv[i]);
        while (iss >> token)
        {
            if (is_valid_int(token))
            {
                long value = std::atoi(token.c_str());
                if (std::find(input_sequence.begin(), input_sequence.end(), value) != input_sequence.end())
                    return (false);
                input_sequence.push_back(std::atoi(token.c_str()));
            }
            else
                return (false);
        }
    }
    return (true);
}