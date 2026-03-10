/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:59:31 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/07 11:06:26 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void    swap(T& a, T& b)
{
    T   temp = a;

    a = b;
    b = temp;
}

template <typename T>
T const&    min(const T& a, const T& b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T>
T const&  max(const T&a, const T& b)
{
    if (a > b)
        return a;
    return b;
}