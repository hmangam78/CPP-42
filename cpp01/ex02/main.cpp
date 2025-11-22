/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:28:14 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/26 16:41:42 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		str =  "HI THIS IS BRAIN";
	std::string*	string_PTR = &str;
	std::string&	string_REF = str;

	std::cout << "memory address of the string variable: " << &str << std::endl;
	std::cout << "memory address held by stringPTR:      " << string_PTR << std::endl;
	std::cout << "memory address held by stringREF:      " << &string_REF << std::endl;

	std::cout << "value of the string variable:  " << str << std::endl;
	std::cout << "value pointed to by stringPTR: " << *string_PTR << std::endl;
	std::cout << "value pointed to by stringREF: " << string_REF << std::endl;
}