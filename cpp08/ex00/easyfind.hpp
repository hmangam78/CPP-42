/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:19:23 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/20 20:28:51 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <exception>

class ItemNotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Item not found");
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int to_find)
{
    typename T::iterator iter;

    iter = std::find(container.begin(), container.end(), to_find);
    if (iter == container.end())
        throw ItemNotFoundException();
    return (iter);
}