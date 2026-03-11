/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:51:29 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/04 19:46:59 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.hpp"
#include <limits.h>

int main( void )
{
	Point a(4, 4);
	Point b(6, 8);
	Point c(8, 4);
	Point point(5, 6);
	std::cout << "a = " << a << " b = " << b << " c = " << c << " point = " << point <<  std::endl;
	std::cout << bsp(a, b, c, point) << std::endl;
	point.setY(6.1f);	
	std::cout << "a = " << a << " b = " << b << " c = " << c << " point = " << point <<  std::endl;
	std::cout << bsp(a, b, c, point) << std::endl;
	a.setX(3.8f);
	std::cout << "a = " << a << " b = " << b << " c = " << c << " point = " << point <<  std::endl;
	std::cout << bsp(a, b, c, point) << std::endl;
	point.setValues(6, 8);
	std::cout << "a = " << a << " b = " << b << " c = " << c << " point = " << point <<  std::endl;
	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}