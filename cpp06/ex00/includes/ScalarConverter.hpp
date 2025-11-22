/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:09:53 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/18 16:02:43 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cerrno>

#define I_MAX std::numeric_limits<int>::max()
#define I_MIN std::numeric_limits<int>::min()
#define F_MAX std::numeric_limits<float>::max()
#define D_MAX std::numeric_limits<double>::max()

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter(void);
    public:
        static void convert(const std::string& input);
};
