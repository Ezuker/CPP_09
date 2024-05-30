/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:05 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/30 20:22:07 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();
        
        void    parseInput(char **array);
        void    printContainer();
        void    sortVector();
        void    sortDeque();
        void    printPerf();
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        uint64_t    _dequeTime;
        uint64_t    _vectorTime;
};