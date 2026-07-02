/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:02:05 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/07/02 17:50:48 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	this->counter = 0;
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

void	PmergeMe::ford_vector(int recurs_lvl)
{
	std::vector<std::pair<int, int> > vect_pair;
	int	n_per_pair = 1u << recurs_lvl;
	vect_pair = init_container<std::vector<std::pair<int, int> > >(this->_vec, n_per_pair);
	if (vect_pair.empty())
		return;
	this->ford_vector(recurs_lvl + 1);
	std::vector<int> main_chain;
	std::vector<int> pend;
	if (vect_pair.size() < 2)
		return;
	main_chain = init_chains(vect_pair, n_per_pair, pend);
	use_jacobsthal(vect_pair, n_per_pair, main_chain, pend);
	std::copy(main_chain.begin(), main_chain.end(), this->_vec.begin());
}

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

void	PmergeMe::sort_vector()
{
	this->counter = 0;
	std::cout << "Worst possible amount of comparisons " << F(this->_vec.size()) << std::endl;
	this->ford_vector(0);
	std::cout << "Amount of comparisons done " << this->counter << std::endl;
	std::cout << "sorted ";
	print_container(this->_vec);
}

void	PmergeMe::ford_deque(int recurs_lvl)
{
	std::deque<std::pair<int, int> > deq_pair;
	int	n_per_pair = 1u << recurs_lvl;
	deq_pair = init_container<std::deque<std::pair<int, int> > >(this->_deq, n_per_pair);
	if (deq_pair.empty())
		return;
	// std::cout << "deque current Pairs: ";
	// print_container_pair(deq_pair);
	// std::cout << std::endl;
	// std::cout << "deque: ";
	// print_container(this->_deq);
	// std::cout << std::endl;
	this->ford_deque(recurs_lvl + 1);
	std::deque<int> main_chain;
	std::deque<int> pend;
	if (deq_pair.size() < 2)
		return;
	main_chain = init_chains<std::deque<int> >(deq_pair, n_per_pair, pend);
	use_jacobsthal(deq_pair, n_per_pair, main_chain, pend);
	std::copy(main_chain.begin(), main_chain.end(), this->_deq.begin());
}

void	PmergeMe::sort_deque()
{
	this->counter = 0;
	std::cout << "Worst possible amount of comparisons " << F(this->_deq.size()) << std::endl;
	this->ford_deque(0);
	std::cout << "Amount of comparisons done " << this->counter << std::endl;
	std::cout << "sorted ";
	print_container(this->_deq);
}