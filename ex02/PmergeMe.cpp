/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:02 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/31 15:53:55 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

void	PmergeMe::parseInput(char **array)
{
	int i = 1;
	while (array[i])
	{
		long double input_ld = std::strtold(array[i], NULL);
		if (input_ld - (int)input_ld == 0 && (int)input_ld <= 0x7FFFFFFF && (int)input_ld >= 0)
		{
			this->_vector.push_back((int)input_ld);
			this->_deque.push_back((int)input_ld);
		}
		else
		{
			throw std::exception();
		}
		i++;
	}
}

void	PmergeMe::printContainer()
{
	std::vector<int>::iterator it = this->_vector.begin();
	for (; it != this->_vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printPerf()
{
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque : ";
	std::cout << this->_dequeTime << std::setprecision(5) << " sec" << std::endl;
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : ";
	std::cout << this->_vectorTime << std::setprecision(5) << " sec" << std::endl;
}

void	PmergeMe::sortDeque()
{
	clock_t start, end;

	start = clock();
	std::sort(this->_deque.begin(), this->_deque.end());
	end = clock();
	this->_dequeTime = double(end - start) / double(CLOCKS_PER_SEC);
}

#include <unistd.h>
void	PmergeMe::sortVector()
{
	clock_t start;

	start = clock();
	usleep(1000000);
	std::cout << "hihi" << std::endl;
	// std::sort(this->_vector.begin(), this->_vector.end());
	this->_vectorTime = double(clock() - start) / double(CLOCKS_PER_SEC);
}
