/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:22:50 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/11 11:26:18 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Wrong usage, use: 'RPN \"expression\"'" << std::endl;
        return (1);
    }
    if (!valid_expression(argv[1]))
    {
        std::cerr << "Error." << std::endl;
        return (1);
    }
    try
    {
        eval_expression(argv[1]);
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}