/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:15:34 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/12/11 11:20:44 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include "../includes/MyExceptions.hpp"

void    eval_expression(char *str)
{
    std::stack<int> res_stack;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]))
            res_stack.push((str[i] - '0'));
        if (is_operator(str[i]))
        {
            if (res_stack.empty())
                throw (MyExceptions::NoOperands());
            int b = res_stack.top();
            res_stack.pop();
            if (res_stack.empty())
                throw (MyExceptions::NoOperands());
            int a = res_stack.top();
            res_stack.pop();
            if (str[i] == '+')
            res_stack.push(a + b);
            else if (str[i] == '-')
            res_stack.push(a - b);
            else if (str[i] == '*')
            res_stack.push(a * b);
            else if (str[i] == '/')
            {
                if (b == 0)
                throw (MyExceptions::DivideByZero());
                res_stack.push(a / b);
            }
        }
        else
            continue;
    }
    if (res_stack.size() == 1)
        std::cout << res_stack.top() << std::endl;
    else
        throw (MyExceptions::NoOperators());
}