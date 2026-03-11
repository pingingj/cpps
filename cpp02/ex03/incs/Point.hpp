/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:13:15 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/04 19:37:54 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#ifndef POINT_HPP
#define POINT_HPP

class Point
{
	private:
		Fixed	x;
		Fixed	y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &obj);
		Point	&operator=(const Point &obj);
		~Point();
		Fixed getX() const;
		Fixed getY() const;
		void	setX(const float x);
		void	setY(const float y);
		void	setValues(const float x, const float y);
};

bool	bsp(const Point a,const Point b,const Point c,const Point point);
std::ostream& operator<<(std::ostream& stream, const Point& point);

#endif