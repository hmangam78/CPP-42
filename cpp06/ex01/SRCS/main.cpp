/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:35:50 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/07 09:48:14 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int main(void)
{
    Data*	data_instance = new Data();
    Data*	data_check;

    std::cout << "Address of data_instance: " << Serializer::serialize(data_instance) << std::endl;
    data_check = Serializer::deserialize(Serializer::serialize(data_instance));
	std::cout << "Address of data_check: " << Serializer::serialize(data_check) << std::endl;
	if (data_check == data_instance)
		std::cout << "Same address" << std::endl;
	else
		std::cout << "Wrong address" << std::endl;
	delete data_instance;
	return 0;
}