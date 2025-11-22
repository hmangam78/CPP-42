/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:26:20 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/07 10:45:36 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));

    Base    *ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;

    return 0;    
}