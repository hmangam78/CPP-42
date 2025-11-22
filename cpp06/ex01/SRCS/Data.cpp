/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:20:07 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/07 09:46:20 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data(void) : _data_1(0), _data_2(0) {}
Data::Data(const Data& other) : _data_1(other._data_1), _data_2(other._data_2) {}
Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        this->_data_1 = other._data_1;
        this->_data_2 = other._data_2;
    }
    return (*this);
}
Data::~Data(void) {}