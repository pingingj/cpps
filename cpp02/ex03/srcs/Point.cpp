/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:15:52 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/04 19:37:31 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Point.hpp"

Point::Point()
{
	std::cout << "Default Point constructor" << std::endl;
	this->x = 0;
	this->y = 0;
}

Point::Point(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point &obj)
{
	*this = obj;
}

Point	&Point::operator=(const Point &obj)
{
	if (this != &obj)
	{
		this->x = obj.x;
		this->y = obj.y;
	}
	return (*this);
}

Point::~Point()
{
	// std::cout << "Default destructor" << std::endl;
}

Fixed	Point::getX() const
{
	return (this->x);	
}

Fixed	Point::getY() const
{
	return (this->y);
}

void	Point::setX(const float x)
{
	this->x = x;
}

void	Point::setY(const float y)
{
	this->y = y;
}

void	Point::setValues(const float x, const float y)
{
	this->x = x;
	this->y = y;
}

std::ostream& operator<<(std::ostream& stream, const Point& point)
{
	stream << "(" << point.getX() << "," << point.getY() << ")";
	return (stream);
}