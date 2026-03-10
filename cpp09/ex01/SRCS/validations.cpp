/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:39:26 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/16 13:52:52 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

bool    valid_chars(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]) || is_operator(str[i]))
        {
            if (str[i + 1] != '\0' && (!isspace(str[i + 1])))
                return (false);
        }
        else if (isspace(str[i]))
            continue ;
        else
            return (false);
    }
    return (true);
}

bool    valid_numbers(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]) && isdigit(str[i + 1]))
            return (false);
    }
    return (true);
}

bool    valid_expression(char *str)
{
    if (!valid_chars(str))
        return (false);
    if (!valid_numbers(str))
        return (false);
    return (true);
}

bool    is_operator(char c)
{
    return ((c == '+') || (c == '-') || (c == '*') || (c == '/'));
}