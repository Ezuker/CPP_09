/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:05 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/26 19:11:45 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iterator>
#include <iomanip>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		
		void    parseInput(char **array);
		void    printContainer();
		void    printPerf();
		void    sort();
	private:
		PmergeMe(const PmergeMe &cpy);
		PmergeMe	&operator=(const PmergeMe &rhs);
		template <class Container, class PairContainer>
		void    sortContainer(Container &content, PairContainer &uPair);

		template <class PairContainer>
		void    recursiveSort(PairContainer &content, int left, int right);

		template <class PairContainer>
		void    merge(PairContainer &content, int left, int middle, int right);

		template <class Container>
		typename Container::iterator    binarySearch(Container &content, typename Container::iterator xi, int toPush);
		std::vector<int> _vector;
		std::deque<int> _deque;
		double	_dequeTime;
		double	_vectorTime;
};
