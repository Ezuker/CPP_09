/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:05 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/31 15:32:41 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>


class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		
		void	parseInput(char **array);
		void	printContainer();
		void	sortVector();
		void	sortDeque();
		void	printPerf();
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		double				_vectorTime;
		double				_dequeTime;
};
