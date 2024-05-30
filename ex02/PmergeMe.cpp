/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:02 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/30 23:57:03 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

void    PmergeMe::parseInput(char **array)
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

void    PmergeMe::printContainer()
{
    std::vector<int>::iterator it = this->_vector.begin();
    for (; it != this->_vector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::printPerf()
{

}

void    PmergeMe::sortDeque()
{

}

void    PmergeMe::sortVector()
{
    
}