/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:07:08 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/07 15:48:22 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

void    printSeparator(void)
{
    std::cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>" << std::endl;
}
void    digits_in_array(const char& c)
{
    std::cout << "Char '" << c << "' ";
    if (isdigit(c))
        std::cout << "is a digit char" << std::endl;
    else
        std::cout << "is not a digit char" << std::endl;
}

void    upper_caser(char& c)
{
    if ((c >= 'a') && (c <= 'z'))
        c -= 32;
}

void    times_10(int& num)
{
    num *= 10;
}

void    print_array(int* array, size_t size)
{
    std::cout << "{";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << array[i];
        if (i < ( size - 1))
            std::cout << ", ";
    }
    std::cout << "}";
}

int main(void)
{
    std::string str = "hey 42, what's up?";

    std::cout << "Original: " << str << std::endl;
    iter(&str[0], static_cast<size_t>(str.length()), upper_caser);
    std::cout << "Modified: " << str << std::endl;
    
    printSeparator();

    int array[5] = {1, 2, 3, 4, 5};

    std::cout << "Original: ";
    print_array(array, 5);
    std::cout << std::endl;
    iter(array, 5, times_10);
    std::cout << "Modified: ";
    print_array(array, 5);
    std::cout << std::endl;

    printSeparator();
    
    std::string str2 = "hey 42, this is cpp07";
    iter(&str2[0], static_cast<size_t>(str2.length()), digits_in_array);

    printSeparator();
    
    return 0;
}