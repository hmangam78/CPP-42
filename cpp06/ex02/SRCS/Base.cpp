/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:02:00 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/22 14:40:13 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base(void) {}

Base*   generate(void)
{
    Base*   ptr;
    int random_num = (rand() % 3) + 1;
    switch (random_num)
    {
    case 1:
        ptr = new A();
        return (ptr);
    case 2:
        ptr = new B();
        return (ptr);
    case 3:
        ptr = new C();
        return (ptr);
    default:
        return NULL;
    }
}

void	identify(Base* p)
{
    if (A* a_ptr = dynamic_cast<A*>(p))
    {
        std::cout << "The object is an A object" << std::endl;
        (void)a_ptr;
        return ;
    }
    else if (B* b_ptr = dynamic_cast<B*>(p))
    {
        std::cout << "The object is a B object" << std::endl;
        (void)b_ptr;
        return ;
    }
    else if (C* c_ptr = dynamic_cast<C*>(p))
    {
        std::cout << "The object is a C object" << std::endl;
        (void)c_ptr;
        return ;
    }
    else
        std::cout << "Error while casting the pointer" << std::endl;
}
void	identify(Base& p)
{
    try
    {
       A& a_ref = dynamic_cast<A&>(p);
       std::cout << "The object is an A object" << std::endl;
       (void)a_ref;
       return ;
    }
    catch (const std::exception& e) {}
    try
    {
       B& b_ref = dynamic_cast<B&>(p);
       std::cout << "The object is a B object" << std::endl;
       (void)b_ref;
       return ;
    }
    catch (const std::exception& e) {}
    try
    {
       C& c_ref = dynamic_cast<C&>(p);
       std::cout << "The object is a C object" << std::endl;
       (void)c_ref;
       return ;
    }
    catch (const std::exception& e) {}
    std::cout << "Error while casting the reference" << std::endl;
}