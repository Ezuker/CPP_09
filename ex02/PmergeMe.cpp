/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:02 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/02 03:05:58 by bcarolle         ###   ########.fr       */
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
	// std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque : ";
	// std::cout << this->_dequeTime << std::setprecision(5) << " sec" << std::endl;
	// std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : ";
	// std::cout << this->_vectorTime << std::setprecision(5) << " sec" << std::endl;
}


void    PmergeMe::sort()
{
	std::vector<std::pair<int, int> > uPair;
	std::deque<std::pair<int, int> > uDeque;

    this->sortContainer(this->_vector, uPair);
    this->sortContainer(this->_deque, uDeque);
}

/*
 * First of the pair is the max and the second one the lowest
 *
*/
template <class Container, class PairContainer>
void    PmergeMe::sortContainer(Container &content, PairContainer &uPair)
{
	(void)uPair;
	PairContainer	pairContent;
    /* Group per pair */
    typename Container::iterator it = content.begin();
    while (it != content.end())
    {
        int first = *it;
        ++it;
        if (it != content.end()) {
            int second = *it;
			if (first > second)
				pairContent.push_back(std::make_pair(first, second));
			else
				pairContent.push_back(std::make_pair(second, first));
            ++it;
        }
    }
	if (!pairContent.size())
		return;

	Container sortedFinal;
    recursiveSort(pairContent, 0, pairContent.size() - 1, content);
	
	for (typename PairContainer::iterator it = pairContent.begin(); it != pairContent.end(); ++it)
		sortedFinal.push_back((*it).first);

	content = sortedFinal;
	content.insert(content.begin(), pairContent[0].second);
	pairContent.erase(pairContent.begin());
	for (typename PairContainer::iterator it = pairContent.begin(); it != pairContent.end(); ++it)
		content.insert(binarySearch(content, (*it).second), (*it).second);
}

template <class Container, class Type>
void PmergeMe::recursiveSort(Container &content, int left, int right, Type &containerType)
{
    if (left < right) {
        int middle = left + (right - left) / 2;
        recursiveSort(content, left, middle, containerType);
        recursiveSort(content, middle + 1, right, containerType);
        merge(content, left, middle, right, containerType);
    }
}

template <class Container, class Type>
void PmergeMe::merge(Container &content, int left, int middle, int right, Type &containerType)
{
	(void)containerType;
    int i, j, k;

    Type L(middle - left + 1), R(right - middle);

    for (i = 0; i < middle - left + 1; i++)
        L[i] = content[left + i].first;

    for (j = 0; j < right - middle; j++)
        R[j] = content[middle + 1 + j].first;

    i = 0;
    j = 0;
    k = left;
    while (i < middle - left + 1 && j < right - middle) 
	{
        if (L[i] <= R[j]) 
		{
            content[k].first = L[i];
            i++;
        } 
		else 
		{
            content[k].first = R[j];
            j++;
        }
        k++;
    }
    while (i < middle - left + 1)
	{
        content[k].first = L[i];
        i++;
        k++;
    }
    while (j < right - middle) 
	{
        content[k].first = R[j];
        j++;
        k++;
    }
}

template <class Container>
typename Container::iterator	PmergeMe::binarySearch(Container &content, int toPush)
{
	int left = 0;
	int right = content.size() - 1;
	while (left <= right)
	{
		int middle = floor((left + right) / 2);
		if (content[middle] < toPush)
			left = middle + 1;
		else if (content[middle] > toPush)
			right = middle;
		else
			return content.begin() + middle;
		if (content[left] > toPush && content[right] > toPush)
			return content.begin() + left;
		if (content[left] < toPush && content[right] < toPush)
			return content.begin() + right + 1;
	}
	return content.begin();
}