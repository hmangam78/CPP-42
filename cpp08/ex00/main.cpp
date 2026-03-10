/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:30:40 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/21 08:27:51 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include "easyfind.hpp"

void    printSeparator(void)
{
    std::cout << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>" << std::endl;
    std::cout << std::endl;
}

int main(void)
{
    printSeparator();
    std::cout << "Testing LIST container" << std::endl;
    
    std::list<int>  my_list;
    
    // Filling up the list
    for (int i = 0; i < 30; i++)
        my_list.push_back(i);
    // Trying to find num inside the list
    try 
    {
        int num = 25;
        std::cout << "Looking for: " << num << " >> " << *easyfind(my_list, num) << std::endl;
        num = 1;
        std::cout << "Looking for: " << num << " >> " << *easyfind(my_list, num) << std::endl;
        num = 40;
        std::cout << "Looking for: " << num << " >> " << *easyfind(my_list, num) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    printSeparator();

    std::cout << "Testing VECTOR container" << std::endl;
    
    std::vector<int>  my_vect;
    // Filling up the vector
    for (int i = 0; i < 30; i++)
        my_vect.push_back(i);
    // Trying to find num inside the vector
    try 
    {
        int num = 25;
        std::cout << "Looking for: " << num << " >> " << *easyfind(my_vect, num) << std::endl;
        num = 1;
        std::cout << "Looking for: " << num << " >> " << *easyfind(my_vect, num) << std::endl;
        num = 40;
        std::cout << "Looking for: " << num << " >> " << *easyfind(my_vect, num) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    printSeparator();

    std::cout << "Testing DEQUE container" << std::endl;
    
    std::deque<int>  my_deque;
    // Filling up the deque
    for (int i = 0; i < 30; i++)
        my_deque.push_back(i);
    // Trying to find num inside the deque
    try 
    {
        int num = 25;
        std::cout << "Looking for: " << num << " >> " << *easyfind(my_deque, num) << std::endl;
        num = 1;
        std::cout << "Looking for: " << num << " >> " << *easyfind(my_deque, num) << std::endl;
        num = 40;
        std::cout << "Looking for: " << num << " >> " << *easyfind(my_deque, num) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}