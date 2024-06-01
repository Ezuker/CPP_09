/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:05 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/01 23:36:17 by bcarolle         ###   ########.fr       */
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
        template <class Container>
        void    sortContainer(Container &content);
        template <class Container>
        typename Container::iterator    binarySearch(Container &content, int toPush);
        std::vector<int> _vector;
        std::deque<int> _deque;
};