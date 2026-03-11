/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:54:25 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/02/04 17:30:10 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits>

class Fixed
{
	private:
		int	fixed_value;
		static const int	fract_bits;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed &operator=(const Fixed &obj);
		bool	operator>(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;
		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static	Fixed	&min(Fixed &a, Fixed &b);
		static	Fixed	&max(Fixed &a, Fixed &b);
		static	const Fixed	&min(const Fixed &a, const Fixed &b);
		static	const Fixed	&max(const Fixed &a, const Fixed &b);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& f);

#endif