/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:05 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/02 02:46:19 by bcarolle         ###   ########.fr       */
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
        template <class Container, class PairContainer>
        void    sortContainer(Container &content, PairContainer &uPair);

        template <class Container, class Type>
        void    recursiveSort(Container &content, int left, int right, Type &containerType);

        template <class Container, class Type>
        void    merge(Container &content, int left, int middle, int right, Type &containerType);

        template <class Container>
        typename Container::iterator    binarySearch(Container &content, int toPush);
        std::vector<int> _vector;
        std::deque<int> _deque;
};