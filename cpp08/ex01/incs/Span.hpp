/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:22:02 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/19 18:16:04 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	private:
		std::vector<int> span;
		unsigned int	 N;
	public:
		//constructors
		Span();
		Span(unsigned int N);
		Span(const Span &obj);
		Span &operator=(const Span &obj);
		~Span();

		//getters
		std::vector<int> getSpan() const;

		void	addNumber(int val);
		int		shortestSpan();
		int		longestSpan();
		void	addMoreNums(int start, int end);
};

std::ostream &operator<<(std::ostream &os, const Span &obj);


#endif