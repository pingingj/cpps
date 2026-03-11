/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:55:29 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/03 22:20:47 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Fixed.hpp"

const int	Fixed::fract_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->fixed_value = obj.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (this->fixed_value);
}

void	Fixed::setRawBits(int raw)
{
	this->fixed_value = raw;
}

//New to the excercise

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_value = num << fract_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_value = roundf(num * (1 << fract_bits));
}

int	Fixed::toInt() const
{
	return (this->fixed_value >> fract_bits);
}

float	Fixed::toFloat() const
{
	return (this->fixed_value / (float)(1 << fract_bits));
}

std::ostream& operator<<(std::ostream& stream, const Fixed& f)
{
	stream << f.toFloat();
	return (stream);
}
