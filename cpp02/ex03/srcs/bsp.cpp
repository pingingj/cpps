/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:06:12 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/04 17:26:52 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.hpp"

static Fixed	check_side(const Point a, const Point b,const Point point)
{
	return ((point.getX() - a.getX()) * (b.getY() - a.getY()) - (point.getY() - a.getY()) * (b.getX() - a.getX()));
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	sides[3];
	sides[0] = check_side(a, b, point);
	sides[1] = check_side(b, c, point);
	sides[2] = check_side(c, a, point);
	if (sides[0] >= 0 && sides[1] >= 0 && sides[2] >= 0)
		return (true);
	if (sides[0] <= 0 && sides[1] <= 0 && sides[2] <= 0)
		return (true);
	return (false);
}
