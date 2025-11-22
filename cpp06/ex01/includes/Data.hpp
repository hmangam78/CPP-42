/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:16:52 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/06 23:21:53 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Data
{
    private:
        int _data_1;
        int _data_2;
    public:
        Data(void);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data(void);
};