/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:02:05 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/06/24 22:07:49 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_hasStraggler = false;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		this->_vec = obj._vec;
		this->_deq = obj._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	
}

bool PmergeMe::parse(char *argv)
{
	std::string str = argv;
	if (str.empty())
	{
		std::cerr << "Error: empty input" << std::endl;	
		return (false);
	}
	if (str.find_first_not_of("1234567890") != str.npos)
	{
		std::cerr << "Error: input is not an positive integer " << str	<< std::endl;
		return (false);
	}
	if (std::strtod(argv, NULL) > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: input is higher than a positive integer " << str << std::endl;	
		return (false);
	}
	int	val = std::atoi(argv);
	this->_vec.push_back(val);
	this->_deq.push_back(val);

	return (true);
}

void	PmergeMe::sort_

void	PmergeMe::sort_vector()
{
	std::vector<std::pair<int, int> > vect_pair;
	vect_pair = init_container<std::vector<std::pair<int, int> > >();
	print_container(vect_pair);
}

void	PmergeMe::sort_deque()
{
	std::deque<std::pair<int, int> > deq_pair;
	deq_pair = init_container<std::deque<std::pair<int, int> > >();
	print_container(deq_pair);
}