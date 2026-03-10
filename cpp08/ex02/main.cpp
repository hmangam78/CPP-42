/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 20:23:51 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/27 14:42:22 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include "MutantStack.hpp"

void    displaySeparator(void)
{
    std::cout << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>" << std::endl;
    std::cout << std::endl;
}

void    displayMessage(std::string str)
{
    std::cout << str << std::endl;
}

int main(void)
{
    displaySeparator();
    displayMessage("MutantStack push and pop test");
    MutantStack<int> my_stack;
    displayMessage("Pushing '42' into the MutantStack");
    my_stack.push(42);
    std::cout << my_stack.top() << std::endl;
    displayMessage("Pushing '22' into the MutantStack");
    my_stack.push(22);
    std::cout << my_stack.top() << std::endl;
    displayMessage("Stack size:");
    std::cout << my_stack.size() << std::endl;
    displayMessage("Popping top element from the MutantStack");
    my_stack.pop();
    displayMessage("Top element in the MutantStack");
    std::cout << my_stack.top() << std::endl;
    displayMessage("Stack size:");
    std::cout << my_stack.size() << std::endl;
    
    displaySeparator();
    displayMessage("Pushing '100', '75', '50' and '25' into the MutantStack");
    my_stack.push(100);
    my_stack.push(75);
    my_stack.push(50);
    my_stack.push(25);
    displayMessage("Iterating over the MutantStack to print its contents (beginning to end)");
    for (MutantStack<int>::iterator it = my_stack.begin(); it != my_stack.end(); ++it)
        std::cout << *it << std::endl;
    
    displaySeparator();
    displayMessage("Iterating over the MutantStack to print its contents (end to beginning)");
    for (MutantStack<int>::reverse_iterator it = my_stack.rbegin(); it != my_stack.rend(); ++it)
        std::cout << *it << std::endl;
    displaySeparator();

    return 0;
}