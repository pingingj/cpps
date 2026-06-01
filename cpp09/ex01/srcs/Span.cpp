/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 17:22:00 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/05/19 18:28:49 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Span.hpp"
#include <limits>
#include <algorithm>


Span::Span()
{
	// std::cout << "Default span constructor" << std::endl;
	this->N = 0;
}

Span::Span(unsigned int N)
{
	std::cout << "Span constructor with " << N << " numbers" << std::endl;
	this->N = N;
	// for(unsigned int i = 0; i < N; i++)
	// 	this->span.push_back(i);
}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->span.erase(this->span.begin(), this->span.end());
		this->span = obj.span;
		this->N = obj.N;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span Destructor called" << std::endl;
	this->span.erase(this->span.begin(), this->span.end());
}

std::vector<int> Span::getSpan() const
{
	return (this->span);
}

void	Span::addNumber(int val)
{
	if (this->span.size() < this->N)
		this->span.push_back(val);
	else
		throw std::length_error("Exceeded the amount of elements!");
}

int		Span::shortestSpan()
{
	int res;
	int diff = std::numeric_limits<int>::max();
	std::vector<int>::iterator i = this->span.begin();
	std::vector<int>::iterator j;
	if (this->span.size() <= 1)
		throw std::out_of_range("Span is too small!");
	while(i != this->span.end())
	{
		j = i + 1;
		while(j != this->span.end())
		{
			res = std::abs(*i - *j);
			if (res < diff)
				diff = res;
			j++;
		}
		i++;
	}
	return (diff);
}

int		Span::longestSpan()
{
	int res;
	int big = 0;
	std::vector<int>::iterator i = this->span.begin();
	std::vector<int>::iterator j;
	if (this->span.size() <= 1)
		throw std::out_of_range("Span is too small!");
	while(i != this->span.end())
	{
		j = i + 1;
		while(j != this->span.end())
		{
			res = std::abs(*i - *j);
			if (res > big)
				big = res;
			j++;
		}
		i++;
	}
	return (big);
}


void	Span::addMoreNums(int start, int end)
{
	if (start > end)
		throw std::invalid_argument("Invalid range of numbers, start has to be smaller than end of range!");
	if (this->span.size() >= this->N)
		throw std::length_error("Exceeded the amount of elements!");
	for (int i = start; i <= end; i++)
		this->addNumber(i);
}

std::ostream &operator<<(std::ostream &os, const Span &obj)
{
	std::vector<int> tmp;
	
	tmp = obj.getSpan();
	if (tmp.empty())
		os << "No elements in span";
	std::vector<int>::iterator i = tmp.begin();
	while(i < tmp.end())
	{
		os << *i << std::endl;
		i++;
	}
	return (os);
}