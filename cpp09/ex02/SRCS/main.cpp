/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:46:09 by hgamiz-g          #+#    #+#             */
/*   Updated: 2026/03/10 16:41:25 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ========================== MAIN ENTRY POINT ============================== */

int main(int argc, const char **argv)
{
    std::vector<int>    input_sequence;

    if (argc == 1)
    {
        std::cerr << "Error. Usage: 'PmergeMe <sequence of ints>'" << std::endl;
        return (1);
    }
    if (!valid_sequence(argv))
    {
        std::cerr << "Error. Invalid characters in input sequence." << std::endl;
        return (1);
    }
    if (!read_sequence(argv, input_sequence))
    {
        std::cerr << "Error. Invalid number found in sequence." << std::endl;
        return (1);
    }
    if (input_sequence.size() == 0)
    {
        std::cout << "Empty list" << std::endl;
        return (0);
    }
    sort(input_sequence);
    return (0);
}