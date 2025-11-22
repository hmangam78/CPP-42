/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:46:50 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/10 09:13:57 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/amateriatest.hpp"

int	main(int args, char **argv)
{
	if (args == 1)
		subject_main();
	else if ((args > 2) || ((args == 2) && (std::string(argv[1]) != "-test")))
	{
		std::cout << "Run without parameters to run the subject's main"
				  << " or run 'materia -test' for extended tests" << std::endl;
	}
	else
		run_tests();
	return (0);
}
