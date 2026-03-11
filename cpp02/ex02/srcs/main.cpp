/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:51:29 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/04 16:01:31 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"
#include <limits.h>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "-----------------Default tests---------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "--------------------My tests-----------------" << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	Fixed const c( Fixed( 5.05f ) / Fixed( 3 ) );
	std::cout << c << std::endl;
	Fixed  d( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << d << std::endl;
	std::cout << "post dec: "<< d-- << std::endl;
	std::cout << d << std::endl;
	std::cout << "pre dec: " << --d << std::endl;
	std::cout << "c < d: " << (c < d) << std::endl;
	std::cout << "c > d: " << (c > d) << std::endl;
	Fixed e = d;
	std::cout << "e > d: " << (e > d) << std::endl;
	std::cout << "e < d: " << (e < d) << std::endl;
	std::cout << "e >= d: " << (e >= d) << std::endl;
	std::cout << "e <= d: " << (e <= d) << std::endl;
	std::cout << "e == d: " << (e == d) << std::endl;
	std::cout << "e != d: " << (e != d) << std::endl;
	std::cout << "e + d: " << (e + d) << std::endl;
	std::cout << "e - d: " << (e - d) << std::endl;
	std::cout << "e * INT_MAX: " << (e * Fixed(INT_MAX)) << std::endl;
	std::cout << "d / 2: " << (d / 2) << std::endl;
	std::cout << "2 == d: " << (Fixed(2) == d) << std::endl;
	std::cout << "2 != d: " << (Fixed(2) != d) << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	return 0;
}