/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:09:56 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/06 23:09:57 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int     main(int args, char **argv)
{
    if (args != 2)
        return 1;
    else if (argv[1] != NULL && argv[1][0] == '\0')
        return 1;
    ScalarConverter::convert(argv[1]);
    return 0;
}