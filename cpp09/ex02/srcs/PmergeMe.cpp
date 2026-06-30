/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- <dgarcez-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:02:05 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/06/30 15:35:56 by dgarcez-         ###   ########.fr       */
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

std::vector<int> PmergeMe::jacobsthal(size_t n)
{
	size_t	num;
	std::vector<int> seq;
	seq.push_back(3);
	if (n <= 2)
		return (seq);
	seq.push_back(5);
	if (n < 5)
		return (seq);
	for(int i = 2; i; i++)
	{
		num = seq[i - 1] + 2 * seq[i - 2];
		if (num >= n)
		{
			seq.push_back(num);
			break ;
		}
		seq.push_back(num);
	}
	return (seq);
}

std::vector	<int>PmergeMe::init_chains(std::vector<std::pair<int, int> > &vect_pair, int &n_per_pair, std::vector<int> &pend)
{
	std::cout << "-----------INITING CHAINS--------" << std::endl;
	std::cout << "N PER PAIR: " << n_per_pair << std::endl;
	// print_container(this->_vec);
	print_container_pair(vect_pair);
	std::vector<int> main_chain;
	for(size_t i = 0; i < vect_pair.size() * 2; i++)
	{
		size_t start = i * n_per_pair;
		size_t end  = start + n_per_pair;
		if(i == 0 || i == 1 || i % 2 != 0)
			main_chain.insert(main_chain.end(),this->_vec.begin() + start, this->_vec.begin() + end);
		else
			pend.insert(pend.end(), this->_vec.begin() + start, this->_vec.begin() + end);
	}
	size_t consumed = vect_pair.size() * 2 * n_per_pair;
	if(consumed + n_per_pair <= _vec.size()) 
		pend.insert(pend.end(), _vec.begin() + consumed, _vec.begin() + consumed + n_per_pair);
	return(main_chain);
}

size_t	PmergeMe::binarysearch(std::vector<int> &main_chain, std::vector<int> &pend, int &to_compare, int &n_per_pair, size_t &right)
{
	(void)pend;
	size_t left = 0;
	while (left <= right)
	{
		size_t middle = (left + right) / 2;
		size_t index = middle * n_per_pair + (n_per_pair - 1);
		// std::cout << "comparing " << to_compare << " with " << main_chain[index] << std::endl;
		if(to_compare < main_chain[index])
		{
			if(middle == 0)
			{
				left = 0;
				break;
			}
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	std::cout << "left: " << left << std::endl;
	return (left);
}

int		find_pair(std::vector<std::pair<int, int> > &vect_pair, int find)
{
	for(size_t i = 0; i < vect_pair.size(); i++)
	{
		if (find == vect_pair[i].first)
			return vect_pair[i].second;
	}
	return (-1);
}

void	PmergeMe::use_jacobsthal(std::vector<std::pair<int, int> > &vect_pair,int &n_per_pair, std::vector<int> &main_chain, std::vector<int> &pend)
{
	std::cout << "----------------------------STARTING JACOBING----------------------------" << std::endl;
	print_container_pair(vect_pair);
	size_t	order = 0;
	size_t	prev_order = 1;
	std::vector<int> seq;

	seq = jacobsthal(pend.size() / n_per_pair);
	int pair_count = pend.size() / n_per_pair + 1;
	// std::cout << "Pair count " << pair_count << std::endl;

	// if (seq.empty() || seq.back() != pair_count)
	// 	seq.push_back(pair_count);
	std::cout << "jacob sequence for size " << pend.size() / n_per_pair << ": ";
	print_container(seq);
	for(size_t i = 0; i < seq.size(); i++)
	{
		order = std::min(seq[i], pair_count);
		for(size_t j = order; j > prev_order; j--)
		{
			// if (j > pend.size())
			// 	j = pend.size() + 1;
			// std::cout << "j: " << j << std::endl;
			int	current_pair = j - 2;
			size_t idx = current_pair * n_per_pair + (n_per_pair - 1);
			int		pair;
			pair = find_pair(vect_pair, pend[idx]);
			size_t right;
			size_t left;
			if (pair == -1)
				right = main_chain.size() / n_per_pair - 1;
			else
				right = std::distance(main_chain.begin(),std::find(main_chain.begin(),main_chain.end(), pair)) / n_per_pair;
			std::cout << "TO INSERT!!!! " << pend[idx] << " pair = " << pair << std::endl;
			std::cout << "current pair: " << current_pair << " vect pair: " << vect_pair[current_pair].second << std::endl; 
			left = binarysearch(main_chain, pend, pend[idx], n_per_pair, right);
			main_chain.insert(main_chain.begin() + left * n_per_pair, pend.begin() + idx - n_per_pair + 1, pend.begin() + idx + 1);
			print_container(main_chain);
		}
		prev_order = order;
	}
}

void	PmergeMe::ford_vector(int recurs_lvl)
{
	std::vector<std::pair<int, int> > vect_pair;
	int	n_per_pair = 1u << recurs_lvl;
	vect_pair = init_container<std::vector<std::pair<int, int> > >(this->_vec, n_per_pair);
	if (vect_pair.empty())
		return;
	std::cout << "number per pair: " << n_per_pair << std::endl;
	std::cout << "current Pairs: ";
	print_container_pair(vect_pair);
	std::cout << std::endl;
	std::cout << "Vector: ";
	print_container(this->_vec);
	std::cout << std::endl;
	this->ford_vector(recurs_lvl + 1);
	std::vector<int> main_chain;
	std::vector<int> pend;
	// std::cout << "vector pair size " << vect_pair.size() << std::endl;
	if (vect_pair.size() < 2)
		return;
	std::cout << "VECTOR: ";
	print_container(this->_vec);
	main_chain = init_chains(vect_pair, n_per_pair, pend);
	std::cout << "Pend: ";
	print_container(pend);
	std::cout << std::endl;
	std::cout << "Main: ";
	print_container(main_chain);
	std::cout << std::endl;
	use_jacobsthal(vect_pair, n_per_pair, main_chain, pend);
	std::copy(main_chain.begin(), main_chain.end(), this->_vec.begin());
}

void	PmergeMe::sort_vector()
{
	this->ford_vector(0);
}

void	PmergeMe::ford_deque(int recurs_lvl)
{
	std::deque<std::pair<int, int> > deq_pair;
	int	n_per_pair = 1u << recurs_lvl;
	deq_pair = init_container<std::deque<std::pair<int, int> > >(this->_deq, n_per_pair);
	if (deq_pair.empty())
		return;
	std::cout << "deque current Pairs: ";
	print_container_pair(deq_pair);
	std::cout << std::endl;
	std::cout << "deque: ";
	print_container(this->_deq);
	std::cout << std::endl;
	this->ford_deque(recurs_lvl + 1);
	std::deque<int> main_deq;
	std::deque<int> pend;
}

void	PmergeMe::sort_deque()
{
	this->ford_deque(0);
	// std::deque<std::pair<int, int> > deq_pair;
	// deq_pair = init_container<std::deque<std::pair<int, int> > >(this->_deq, 0);
	// print_container_pair(deq_pair);
}