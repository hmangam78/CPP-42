/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 20:36:27 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/09/28 18:28:08 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	/*// ========== BATERÍA DE PRUEBAS ==========
	std::cout << "\n===== PRUEBAS DE OPERADORES ARITMÉTICOS =====" << std::endl;
	
	// Declaración de variables para tests
	Fixed x(10.5f);
	Fixed y(3.2f);
	Fixed z(7.0f);
	Fixed w(-2.5f);
	
	std::cout << "x = " << x << ", y = " << y << ", z = " << z << ", w = " << w << std::endl;
	
	// Test suma
	std::cout << "\n--- SUMA ---" << std::endl;
	std::cout << x << " + " << y << " = " << (x + y) << std::endl;
	std::cout << z << " + " << w << " = " << (z + w) << std::endl;
	
	// Test resta
	std::cout << "\n--- RESTA ---" << std::endl;
	std::cout << x << " - " << y << " = " << (x - y) << std::endl;
	std::cout << y << " - " << x << " = " << (y - x) << std::endl;
	
	// Test multiplicación
	std::cout << "\n--- MULTIPLICACIÓN ---" << std::endl;
	std::cout << x << " * " << y << " = " << (x * y) << std::endl;
	std::cout << z << " * " << w << " = " << (z * w) << std::endl;
	
	// Test división
	std::cout << "\n--- DIVISIÓN ---" << std::endl;
	std::cout << x << " / " << y << " = " << (x / y) << std::endl;
	std::cout << z << " / " << Fixed(2) << " = " << (z / Fixed(2)) << std::endl;
	
	std::cout << "\n===== PRUEBAS DE OPERADORES DE COMPARACIÓN =====" << std::endl;
	
	Fixed p(5.5f);
	Fixed q(5.5f);
	Fixed r(8.2f);
	
	std::cout << "p = " << p << ", q = " << q << ", r = " << r << std::endl;
	
	// Test comparaciones
	std::cout << "\n--- COMPARACIONES ---" << std::endl;
	std::cout << p << " < " << r << " = " << (p < r ? "true" : "false") << std::endl;
	std::cout << r << " < " << p << " = " << (r < p ? "true" : "false") << std::endl;
	std::cout << p << " > " << r << " = " << (p > r ? "true" : "false") << std::endl;
	std::cout << r << " > " << p << " = " << (r > p ? "true" : "false") << std::endl;
	std::cout << p << " <= " << q << " = " << (p <= q ? "true" : "false") << std::endl;
	std::cout << p << " >= " << q << " = " << (p >= q ? "true" : "false") << std::endl;
	std::cout << p << " == " << q << " = " << (p == q ? "true" : "false") << std::endl;
	std::cout << p << " != " << r << " = " << (p != r ? "true" : "false") << std::endl;
	
	std::cout << "\n===== PRUEBAS DE INCREMENTO/DECREMENTO =====" << std::endl;
	
	Fixed inc(5.0f);
	std::cout << "Valor inicial: " << inc << std::endl;
	std::cout << "Pre-incremento (++inc): " << ++inc << std::endl;
	std::cout << "Valor después: " << inc << std::endl;
	std::cout << "Post-incremento (inc++): " << inc++ << std::endl;
	std::cout << "Valor después: " << inc << std::endl;
	std::cout << "Pre-decremento (--inc): " << --inc << std::endl;
	std::cout << "Valor después: " << inc << std::endl;
	std::cout << "Post-decremento (inc--): " << inc-- << std::endl;
	std::cout << "Valor final: " << inc << std::endl;
	
	std::cout << "\n===== PRUEBAS DE MIN/MAX =====" << std::endl;
	
	Fixed min1(12.5f);
	Fixed min2(8.7f);
	Fixed min3(12.5f);
	
	std::cout << "min1 = " << min1 << ", min2 = " << min2 << ", min3 = " << min3 << std::endl;
	std::cout << "Fixed::min(" << min1 << ", " << min2 << ") = " << Fixed::min(min1, min2) << std::endl;
	std::cout << "Fixed::max(" << min1 << ", " << min2 << ") = " << Fixed::max(min1, min2) << std::endl;
	std::cout << "Fixed::min(" << min1 << ", " << min3 << ") = " << Fixed::min(min1, min3) << std::endl;
	std::cout << "Fixed::max(" << min1 << ", " << min3 << ") = " << Fixed::max(min1, min3) << std::endl;
	
	// Test con const
	const Fixed const1(15.2f);
	const Fixed const2(9.8f);
	std::cout << "Fixed::min(const " << const1 << ", const " << const2 << ") = " << Fixed::min(const1, const2) << std::endl;
	std::cout << "Fixed::max(const " << const1 << ", const " << const2 << ") = " << Fixed::max(const1, const2) << std::endl;
	
	std::cout << "\n===== PRUEBAS DE CASOS ESPECIALES =====" << std::endl;
	
	Fixed zero(0.0f);
	Fixed negative(-5.3f);
	Fixed positive(5.3f);
	
	std::cout << "Suma con cero: " << positive << " + " << zero << " = " << (positive + zero) << std::endl;
	std::cout << "Multiplicación por cero: " << positive << " * " << zero << " = " << (positive * zero) << std::endl;
	std::cout << "Negativo + Positivo: " << negative << " + " << positive << " = " << (negative + positive) << std::endl;
	std::cout << "Negativo * Negativo: " << negative << " * " << negative << " = " << (negative * negative) << std::endl;
	
	std::cout << "\n===== FIN DE PRUEBAS =====" << std::endl;*/
	
	return 0;
}