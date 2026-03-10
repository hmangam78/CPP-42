/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:46:35 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/08 09:58:59 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(size_t size) : _size(size)
{
    _data = new T[size]();
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
    _data = new T[_size]();
    for (size_t i = 0; i < _size; i++)
        _data[i] = other._data[i];
}

template <typename T>
Array<T>::~Array(void)
{
    delete[] _data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _data;
        _size = other._size;
        _data = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _data[i] = other._data[i];
    }
    return (*this);
}

template <typename T>
size_t Array<T>::size(void) const
{
    return (_size);
}

template <typename T>
T& Array<T>::operator[](size_t i)
{
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return (_data[i]);
}

template <typename T>
const T& Array<T>::operator[](size_t i) const
{
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return (_data[i]);    
}