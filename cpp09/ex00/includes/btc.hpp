/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:17:40 by hgamiz-g          #+#    #+#             */
/*   Updated: 2026/01/14 23:18:29 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <fstream>
#include <climits>

//Conversions
long	dateToInt(const std::string& date);
float	strToFloat(const std::string& value);

//Validations
bool	isValidDateFormat(const std::string& date);
bool	isValidDate(const std::string& date);
bool	isFloat(const std::string& value);

//Parsing
int     parse_database(std::map<long, float>& database);
std::string trim(const std::string& s);

//Display
void	displayDate(long date);
void	db_match(std::string& date, float f_value, std::map<long, float>& database);
void	btc(std::map<long, float>& database, std::ifstream& input);