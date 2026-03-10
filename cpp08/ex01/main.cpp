/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:46:50 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/27 14:33:28 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void    displaySeparator(void)
{  
    std::cout << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>" << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    displaySeparator();
    std::cout << "Testing Span Class capacity" << std::endl;
    Span    my_array = Span(2);

    try 
    {
        my_array.addNumber(1);
        my_array.addNumber(2);
        std::cout << my_array << std::endl;
        my_array.addNumber(3);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    displaySeparator();
    
    std::cout << "Testing shortest and longest span" << std::endl;
    Span    span_array = Span(5);
    for (int i = 0; i < 5; i++)
    {
        span_array.addNumber(50 - (i * i));
    }
    std::cout << span_array << std::endl;
    std::cout << "Shortest span: " << span_array.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span_array.longestSpan() << std::endl;
    displaySeparator();
    
    std::cout << "Testing not enough elements" << std::endl;
    Span    short_array = Span(1);
    short_array.addNumber(1);
    try
    {
        short_array.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    displaySeparator();
    
    unsigned int    size = 1000000;
    std::cout << "Testing very large array [" << size << " integers]" <<std::endl;
    Span    long_array = Span(size);
    std::vector<int> LotsOfRandomNum;
	for (size_t i = 0; i < size; ++i)
		LotsOfRandomNum.push_back(rand());
    long_array.multiADD(LotsOfRandomNum.begin(), LotsOfRandomNum.end());
    
    // Un-comment to visualize the array.
    //std::cout << long_array << std::endl;
    std::cout << "Shortest span: " << long_array.shortestSpan() << std::endl;
    std::cout << "Longest span: " << long_array.longestSpan() << std::endl;
    displaySeparator(); 
    

    return 0;
}