/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:06:21 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/08 09:59:19 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template <typename T>

class Array
{
    private:
        T*      _data;
        size_t  _size;
    public:
        Array(void);
        Array(size_t size);
        Array(const Array& other);
        ~Array(void);
        
        Array& operator=(const Array& other);
        size_t  size(void) const;
        T& operator[](size_t i);
        const T& operator[](size_t i) const;
};

#include "Array.tpp"