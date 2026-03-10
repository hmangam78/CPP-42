/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:06:56 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/27 12:14:15 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"

void    printSeparator(void)
{
    std::cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>" << std::endl;
}

int main(void)
{
    printSeparator();
    int a = 42;
    int b = 4242;
    std::cout << "Min (" << a << ", " << b << "): " << ::min(a, b) << std::endl;
    std::cout << "Max (" << a << ", " << b << "): " << ::max(a, b) << std::endl;
    std::cout << "Swapping..." << std::endl;
    ::swap(a, b);
    std::cout << "Min (" << a << ", " << b << "): " << ::min(a, b) << std::endl;
    std::cout << "Max (" << a << ", " << b << "): " << ::max(a, b) << std::endl;
    
    printSeparator();

    float c = 42.42f;
    float d = 4242.42f;
    std::cout << "Min (" << c << ", " << d << "): " << ::min(c, d) << std::endl;
    std::cout << "Max (" << c << ", " << d << "): " << ::max(c, d) << std::endl;
    std::cout << "Swapping..." << std::endl;
    ::swap(c, d);
    std::cout << "Min (" << c << ", " << d << "): " << ::min(c, d) << std::endl;
    std::cout << "Max (" << c << ", " << d << "): " << ::max(c, d) << std::endl;
    
    printSeparator();
    
    std::string str1 = "abc";
    std::string str2 = "def";
    std::cout << "Min (" << str1 << ", " << str2 << "): " << ::min(str1, str2) << std::endl;
    std::cout << "Max (" << str1 << ", " << str2 << "): " << ::max(str1, str2) << std::endl;
    std::cout << "Swapping..." << std::endl;
    ::swap(str1, str2);
    std::cout << "Min (" << str1 << ", " << str2 << "): " << ::min(str1, str2) << std::endl;
    std::cout << "Max (" << str1 << ", " << str2 << "): " << ::max(str1, str2) << std::endl;
    
    printSeparator();
    return 0;
}