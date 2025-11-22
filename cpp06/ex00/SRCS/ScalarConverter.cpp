/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:09:02 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/06 23:09:03 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static void    display_special_cases(const std::string& input);
static void    format_error(void);
static int     get_format(const std::string& input);
static void    convert_char(const std::string& input);
static void    convert_int(const std::string& input);
static void    convert_fd(const std::string& input);

void ScalarConverter::convert(const std::string& input)
{
    if ((input == "nanf") || (input == "+inff") || (input == "-inff")
        || (input == "nan") || (input == "+inf") || (input == "-inf")
        || (input == "inf") || (input == "inff"))
    {
        display_special_cases(input);
    }
    else
    {
        int format_code = get_format(input);
        switch  (format_code)
        {
            case 0:
                format_error();
                break ;
            case 1:
                convert_char(input);
                break ;
            case 2:
                convert_int(input);
                break ;
            case 3:
                convert_fd(input);
                break;
            case 4:
                convert_fd(input);
                break;
        }
    }
}

static int is_printable(char c)
{
    return ((c > 32) && (c < 127));
}


static void    convert_char(const std::string& input)
{
    char    c = static_cast<char>(input[0]);

    if (!is_printable(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void    convert_int(const std::string& input)
{
    errno = 0;
    char*   endptr = NULL;
    long long num = std::strtoll(input.c_str(), &endptr, 10);
    if (errno == ERANGE)
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: overflow" << std::endl;
        errno = 0;
        long double ldnum = std::strtold(input.c_str(), &endptr);
        if (errno == ERANGE)
        {
            std::cout << "float: overflow" << std::endl;
            std::cout << "double: overflow" << std::endl;
        }
        else
        {
            std::cout << std::fixed << std::setprecision(1);
            if (std::fabs(ldnum) > std::numeric_limits<float>::max())
                std::cout << "float: overflow" << std::endl;
            else
                std::cout << "float: " << static_cast<float>(ldnum) << "f" << std::endl;
            if (std::fabs(ldnum) > std::numeric_limits<double>::max())
                std::cout << "double: overflow" << std::endl;
            else
                std::cout << "double: " << static_cast<double>(ldnum) << std::endl;
        }
        return;
    }
    if (num < 32 || num > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    if (num < I_MIN || num > I_MAX)
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    if (std::fabs(num) > F_MAX)
        std::cout << "float: overflow" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    if (std::fabs(num) > D_MAX)
        std::cout << "double: overflow" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void    convert_fd(const std::string& input)
{
    double   num = std::atof(input.c_str());

    if (num < 32 || num > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
    if (num < I_MIN || num > I_MAX)
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    if (std::fabs(num) > F_MAX)
        std::cout << "float: overflow" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    if (std::fabs(num) > D_MAX)
        std::cout << "double: overflow" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void    format_error(void)
{
    std::cout << "Input error. Invalid format" << std::endl;
}

static int is_char(const std::string& input)
{
    return ((input.length() == 1) && (!isdigit(static_cast<unsigned char>(input[0]))));
}

static int is_int(const std::string& input)
{
    size_t i = 0;

    if ((static_cast<char>(input[0]) == '+') || (static_cast<char>(input[0]) == '-'))
    {
        i++;
        if (i == input.length())
            return 0;
    }
    while (i < input.length())
    {
        if (!isdigit(static_cast<char>(input[i])))
            return 0;
        i++;
    }
    return 1;
}

static int is_float(const std::string& input)
{
    size_t i = 0;

    if ((static_cast<char>(input[0]) == '+') || (static_cast<char>(input[0]) == '-'))
    {
        i++;
        if (i == input.length())
            return 0;
    }
    while (i < input.length())
    {
        while (isdigit(static_cast<char>(input[i])))
            i++;
        if (static_cast<char>(input[i]) == '.')
            i++;
        else
            return 0;
        while (isdigit(static_cast<char>(input[i])))
            i++;
        if (static_cast<char>(input[i]) == 'f')
        {
            i++;
            if (i == input.length())
                return 1;
        }
        else
            return 0;
    }
    return 0;
}

static int is_double(const std::string& input)
{
    size_t i = 0;

    if ((static_cast<char>(input[0]) == '+') || (static_cast<char>(input[0]) == '-'))
    {
        i++;
        if (i == input.length())
            return 0;
    }
    while (i < input.length())
    {
        while (isdigit(static_cast<char>(input[i])))
            i++;
        if (static_cast<char>(input[i]) == '.')
            i++;
        else
            return 0;
        while (isdigit(static_cast<char>(input[i])))
            i++;
        if (i == input.length())
                return 1;
        else
            return 0;
    }
    return 0;
}

static int get_format(const std::string& input)
{
    if (is_char(input))
        return 1;
    else if (is_int(input))
        return 2;
    else if (is_float(input))
        return 3;
    else if (is_double(input))
        return 4;
    else
        return 0;
}

static void display_special_cases(const std::string& input)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if ((input == "nanf") || (input == "nan"))
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if ((input == "inff") || (input == "inf") || (input == "+inff") || (input == "+inf"))
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if ((input == "-inff") || (input == "-inf"))
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}
