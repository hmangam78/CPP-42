/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:45:10 by hgamiz-g          #+#    #+#             */
/*   Updated: 2026/03/10 16:22:52 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <climits>
#include <cstdlib>
#include <sys/time.h>
#include <vector>
#include <deque>

/* ========================== FUNCTION DECLARATIONS ======================== */

bool    valid_sequence(const char **argv);
bool    is_valid_int(const std::string& token);
bool    read_sequence(const char **argv, std::vector<int>& input_sequence);
void    sort(const std::vector<int>& input);

/* ========================== TEMPLATE FUNCTIONS ============================ */

template <typename Container>
void    display_array(const Container& arr, std::string head)
{
    size_t  size = arr.size();

    std::cout << head << ": ";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i != size - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

// MERGE SORT ALGORITHM FOR TESTING, change fordJhonson with merge_sort
//inside sort function to test it.

template <typename Container>
void    merge(Container& arr, size_t left, size_t mid, size_t right)
{
    Container   temp;
    size_t      i = left;
    size_t      j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= right)
        temp.push_back(arr[j++]);
    for (size_t k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

template <typename Container>
void    merge_sort_helper(Container& arr, size_t left, size_t right)
{
    if (left < right)
    {
        size_t mid = left + ((right - left) / 2);
        merge_sort_helper(arr, left, mid);
        merge_sort_helper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

template <typename Container>
void    merge_sort(Container& to_sort)
{
    if (to_sort.size() > 1)
        merge_sort_helper(to_sort, 0, to_sort.size() - 1);
}

template <typename Container>
void    swap(Container& to_sort, int i)
{
    int temp;

    temp = to_sort[i + 1];
    to_sort[i + 1] = to_sort[i];
    to_sort[i] = temp;
}

template <typename Container>
void    binary_search_insert(Container& max, int value, size_t limit)
{
    if (max.size() == 0)
    {
        max.insert(max.begin(), value);
        return ;
    }
    size_t left = 0;
    size_t right = limit + 1;
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (max[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    max.insert(max.begin() + left, value);
}

template <typename Container>
void    create_pairs(const Container& to_sort, std::vector<std::pair<int, int> >& pairs, int& straggler, bool& has_straggler)
{
    for (size_t i = 0; i < to_sort.size() - 1; i += 2)
    {
        if (to_sort[i] > to_sort[i + 1])
            pairs.push_back(std::make_pair(to_sort[i], to_sort[i + 1]));
        else
            pairs.push_back(std::make_pair(to_sort[i + 1], to_sort[i]));
    }
    if (to_sort.size() % 2 == 1)
    {
        straggler = to_sort[to_sort.size() - 1];
        has_straggler = true;
    }
}

template <typename Container>
void    extract_max_chain(const std::vector<std::pair<int, int> >& pairs, Container& max_chain, std::vector<size_t>& pair_indices)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        max_chain.push_back(pairs[i].first);
        pair_indices.push_back(i);
    }
}

inline void    reorder_min_chain(const std::vector<std::pair<int, int> >& pairs, const std::vector<size_t>& sorted_indices, std::vector<int>& ordered_min)
{
    for (size_t i = 0; i < sorted_indices.size(); i++)
    {
        ordered_min.push_back(pairs[sorted_indices[i]].second);
    }
}

struct PendingElement
{
    int value;
    int partner;
};

inline std::vector<size_t> generate_jacobsthal_insertion_order(size_t pending_size)
{
    std::vector<size_t> order;

    if (pending_size <= 1)
        return (order);

    // b1 is inserted first. Insert b2..bn in Jacobsthal block order.
    size_t inserted_until = 1;
    size_t j_prev = 1;
    size_t j_curr = 3;

    while (inserted_until < pending_size)
    {
        size_t bound = j_curr;
        if (bound > pending_size)
            bound = pending_size;
        for (size_t k = bound; k > inserted_until; --k)
            order.push_back(k - 1); // pending index for b_k
        inserted_until = bound;
        if (inserted_until == pending_size)
            break ;
        size_t j_next = j_curr + (2 * j_prev);
        j_prev = j_curr;
        j_curr = j_next;
    }
    return (order);
}

template <typename Container>
size_t  find_value_position(const Container& container, int target)
{
    for (size_t i = 0; i < container.size(); i++)
    {
        if (container[i] == target)
            return (i);
    }
    return (container.size() - 1);
}

template <typename Container>
void    insert_remaining_elements(Container& result, const std::vector<PendingElement>& pending)
{
    std::vector<size_t> order = generate_jacobsthal_insertion_order(pending.size());
    for (size_t i = 0; i < order.size(); i++)
    {
        size_t idx = order[i];
        size_t limit = find_value_position(result, pending[idx].partner);
        binary_search_insert(result, pending[idx].value, limit);
    }
}

template <typename OutputContainer>
OutputContainer   build_result(const std::vector<std::pair<int, int> >& sorted_pairs, int straggler, bool has_straggler)
{
    OutputContainer result;
    std::vector<PendingElement> pending;

    pending.reserve(sorted_pairs.size());
    for (size_t i = 0; i < sorted_pairs.size(); i++)
    {
        PendingElement item;
        item.value = sorted_pairs[i].second;
        item.partner = sorted_pairs[i].first;
        pending.push_back(item);
    }

    result.push_back(pending[0].value); // b1
    for (size_t i = 0; i < sorted_pairs.size(); i++)
        result.push_back(sorted_pairs[i].first);

    insert_remaining_elements(result, pending);
    
    if (has_straggler)
    {
        size_t limit = result.size() - 1;
        binary_search_insert(result, straggler, limit);
    }
    
    return result;
}

template <typename Container>
void    fordJohnson(Container& to_sort)
{
    if (to_sort.size() <= 1)
        return ;
    
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool has_straggler = false;
    
    create_pairs(to_sort, pairs, straggler, has_straggler);

    std::vector<int> max_values;
    max_values.reserve(pairs.size());
    for (size_t i = 0; i < pairs.size(); i++)
        max_values.push_back(pairs[i].first);

    fordJohnson(max_values);

    std::vector<std::pair<int, int> > sorted_pairs;
    sorted_pairs.reserve(pairs.size());
    for (size_t i = 0; i < max_values.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == max_values[i])
            {
                sorted_pairs.push_back(pairs[j]);
                break ;
            }
        }
    }

    to_sort = build_result<Container>(sorted_pairs, straggler, has_straggler);
}
