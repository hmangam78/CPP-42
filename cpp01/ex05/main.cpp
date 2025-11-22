/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 12:11:30 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/27 12:15:06 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	grumpy_customer;

	std::cout << "The grumpy customer is setting a WARNING" << std::endl;
	grumpy_customer.complain("WARNING");
	std::cout << std::endl;
	std::cout << "The grumpy customer is setting a DEBUG" << std::endl;
	grumpy_customer.complain("DEBUG");
	std::cout << std::endl;
	std::cout << "The grumpy customer is setting an ERROR" << std::endl;
	grumpy_customer.complain("ERROR");
	std::cout << std::endl;
	std::cout << "The grumpy customer is setting an INFO" << std::endl;
	grumpy_customer.complain("INFO");
	std::cout << std::endl;
}