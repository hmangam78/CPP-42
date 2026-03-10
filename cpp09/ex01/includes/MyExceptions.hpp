/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:40:00 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/11 11:10:07 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>

class MyExceptions
{
    private:
    
    public:
        MyExceptions();
        MyExceptions(const MyExceptions& other);
        MyExceptions& operator=(const MyExceptions& other);
        ~MyExceptions();
        class DivideByZero : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NoOperands : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class NoOperators : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};