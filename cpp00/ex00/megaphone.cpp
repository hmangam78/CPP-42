/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:21:02 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/25 16:04:39 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int args, char **argv)
{
	int			i;
	size_t		j;
	char		c;
	std::string text;

	if (args == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < args)
		{
			text = argv[i];
			j = 0;
			while (j < text.size())
			{
				c = std::toupper(static_cast<unsigned char>(text[j]));
				std::cout << c;
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
