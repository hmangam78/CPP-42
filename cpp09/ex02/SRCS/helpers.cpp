/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:42:56 by hgamiz-g          #+#    #+#             */
/*   Updated: 2026/01/09 11:16:23 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* ========================== SORTING FUNCTION ============================ */

void    sort(const std::vector<int>& input)
{
    std::vector<int>    to_sort_vector = input;
    std::deque<int>     to_sort_deque = std::deque<int>(input.begin(), input.end());
    struct timeval      start;
    struct timeval      end;

    display_array(input, "Before");
    gettimeofday(&start, NULL);
    //Uncomment next line and comment fordJohnson line to test with merge-sort
    //merge_sort(to_sort_vector);
    fordJohnson(to_sort_vector);
    gettimeofday(&end, NULL);
    
    double elapsed_vector = (end.tv_sec - start.tv_sec) * 1000000.0 + 
                            (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    //Uncomment next line and comment fordJohnson line to test with merge-sort
    //merge_sort(to_sort_deque);
    fordJohnson(to_sort_deque);
    gettimeofday(&end, NULL);

    double elapsed_deque = (end.tv_sec - start.tv_sec) * 1000000.0 + 
                           (end.tv_usec - start.tv_usec);

    display_array(to_sort_vector, "After");
    std::cout << "Time to process a range of " << input.size()
              << " elements with a std::vector: " << elapsed_vector << " us"
              << std::endl;
    std::cout << "Time to process a range of " << input.size()
              << " elements with a std::deque: " << elapsed_deque << " us"
              << std::endl;
}