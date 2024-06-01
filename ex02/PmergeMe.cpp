/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:02 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/01 02:17:14 by bcarolle         ###   ########.fr       */
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


void    PmergeMe::sort()
{
    this->sortContainer(this->_vector);
    this->sortContainer(this->_deque);
}

/*
 * First of the pair is the max and the second one the lowest
 *
*/
template <class Container>
void    PmergeMe::sortContainer(Container &content)
{
    std::vector<std::pair<int, int> > pairContainer;

    /* Group per pair */
    typename Container::iterator it = content.begin();
    while (it != content.end())
    {
        int first = *it;
        ++it;
        if (it != content.end()) {
            int second = *it;
            pairContainer.push_back(std::make_pair(first, second));
            ++it;
        }
    }
    std::cout << pairContainer.begin()->first << " " << pairContainer.begin()->second << std::endl;
}
