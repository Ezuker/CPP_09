/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:02 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/22 16:43:05 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
size_t	jacobsthal (size_t n);

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	*this = cpy;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_vector = rhs._vector;
		this->_deque = rhs._deque;
		this->_vectorTime = rhs._vectorTime;
		this->_dequeTime = rhs._dequeTime;
	}
	return (*this);
}

bool	isDigit(const std::string str)
{
	if (str.size() == 1 && str[0] == '-')
		return false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]) && str[0] != '-')
			return false;
	}
	return true;
}

void	PmergeMe::parseInput(char **array)
{
	int i = 1;
	while (array[i])
	{
		if (!isDigit(array[i]))
			throw std::logic_error("NaN");
		long double input_ld = std::strtold(array[i], NULL);
		if (input_ld - (int)input_ld == 0 && (int)input_ld <= 0x7FFFFFFF && (int)input_ld >= 0)
		{
			this->_vector.push_back((int)input_ld);
			this->_deque.push_back((int)input_ld);
		}
		else
			throw std::logic_error("Too large number and negative one are forbidden");
		i++;
	}
}

void	PmergeMe::printContainer()
{
	{	
		std::cout << "	Vector : ";
		std::vector<int>::iterator it = this->_vector.begin();
		for (; it != this->_vector.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	{	
		std::cout << "	Deque : ";
		std::deque<int>::iterator it = this->_deque.begin();
		for (; it != this->_deque.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
}

void	PmergeMe::printPerf()
{
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque  : ";
	std::cout << std::fixed << this->_dequeTime * 1000000 << std::setprecision(6) << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : ";
	std::cout << std::fixed << this->_vectorTime * 1000000 << std::setprecision(6) << " us" << std::endl;
}


void	PmergeMe::sort()
{
	std::vector<std::pair<int, int> > uPair;
	std::deque<std::pair<int, int> > uDeque;

	clock_t	start;
	start = clock();
	this->sortContainer(this->_vector, uPair);
	this->_vectorTime = double(clock() - start) / double(CLOCKS_PER_SEC);
	start = clock();
	this->sortContainer(this->_deque, uDeque);
	this->_dequeTime = double(clock() - start) / double(CLOCKS_PER_SEC);
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
	recursiveSort(pairContent, 0, pairContent.size() - 1);

	for (typename PairContainer::iterator it = pairContent.begin(); it != pairContent.end(); ++it)
		sortedFinal.push_back((*it).first);

	sortedFinal.insert(sortedFinal.begin(), pairContent.front().second);
	pairContent.erase(pairContent.begin());

	int index = 0;
	for (typename PairContainer::iterator it = pairContent.begin(); it != pairContent.end();)
	{
		size_t groupSize = jacobsthal(index++);
		if (groupSize > pairContent.size())
			groupSize = pairContent.size();
		PairContainer jacobGroup(pairContent.begin(), pairContent.begin() + groupSize);
		for (typename PairContainer::iterator itJacob = jacobGroup.begin(); itJacob != jacobGroup.end(); ++itJacob)
			sortedFinal.insert(binarySearch(sortedFinal, (*itJacob).second), (*itJacob).second);
		pairContent.erase(pairContent.begin(), pairContent.begin() + groupSize);
		if (pairContent.size() == 0)
			break ;
	}

	if (content.size() % 2 == 1)
	{
		int struggler = content.back();
		content = sortedFinal;
		content.insert(binarySearch(content, struggler), struggler);
		return;
	}
	content = sortedFinal;
}

template <class Container>
void PmergeMe::recursiveSort(Container &content, int left, int right)
{
	if (left < right) {
		int middle = left + (right - left) / 2;
		recursiveSort(content, left, middle);
		recursiveSort(content, middle + 1, right);
		merge(content, left, middle, right);
	}
}

template <class Container>
void PmergeMe::merge(Container &content, int left, int middle, int right)
{
	int i, j, k;

	Container L(middle - left + 1), R(right - middle);

	for (i = 0; i < middle - left + 1; i++)
		L[i] = content[left + i];

	for (j = 0; j < right - middle; j++)
		R[j] = content[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < middle - left + 1 && j < right - middle) 
	{
		if (L[i].first <= R[j].first)
			content[k++] = L[i++];
		else 
			content[k++] = R[j++];
	}

	for (; i < middle - left + 1; i++)
		content[k++] = L[i];
	for (; j < right - middle; j++) 
		content[k++] = R[j];
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
			right = middle - 1;
		else
			return content.begin() + middle;
		if (content[left] > toPush && content[right] > toPush)
			return content.begin() + left;
		if (content[left] < toPush && content[right] < toPush)
			return content.begin() + right + 1;
	}
	return content.begin();
}

size_t	jacobsthal (size_t n)
{
	if (n == 0)
		return (2);
	else if (n == 1)
		return (2);
	else
		return (jacobsthal(n - 2) * 2 + jacobsthal(n - 1));
}
