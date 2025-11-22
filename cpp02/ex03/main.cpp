/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:36:27 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/10/09 09:51:53 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"
#include <iostream>

void test_case(const std::string& description, Point a, Point b, Point c, Point point, bool expected)
{
	bool result = bsp(a, b, c, point);
	std::string result_str;
	std::string expected_str;
	std::string status_str;

	std::cout << description << std::endl;
	std::cout << "  Triangle: (" << a.get_x() << "," << a.get_y() << ") (" 
			  << b.get_x() << "," << b.get_y() << ") (" 
			  << c.get_x() << "," << c.get_y() << ")" << std::endl;
	std::cout << "  Point: (" << point.get_x() << "," << point.get_y() << ")" << std::endl;

	if (result)
		result_str = "INSIDE";
	else
		result_str = "OUTSIDE";
	if (expected)
		expected_str = "INSIDE";
	else
		expected_str = "OUTSIDE";

	std::cout << "  Result: " << result_str << " (expected: " << expected_str << ")" << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout << "=== BSP Tests ===" << std::endl << std::endl;

	// Basic triangle: (0,0), (2,0), (1,2)
	Point a(0, 0);
	Point b(2, 0);  
	Point c(1, 2);

	// Test 1: Point inside
	test_case("Test 1: Point inside the triangle", 
				a, b, c, Point(1, 0.5f), true);

	// Test 2: Point outside
	test_case("Test 2: Point outside the triangle", 
				a, b, c, Point(3, 3), false);

	// Test 3: Vertex (Must be false)
	test_case("Test 3: Point on a vertex", 
				a, b, c, Point(0, 0), false);
	
	// Test 4: Point on a border
	test_case("Test 4: Point on ab border", 
				a, b, c, Point(1, 0), false);
	
	// Test 5: Point inside but very close to the border
	test_case("Test 5: Point inside but very close to the border", 
				a, b, c, Point(0.1f, 0.1f), true);
	return 0;
}
