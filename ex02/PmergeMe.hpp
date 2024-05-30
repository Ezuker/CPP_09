/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:05 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/30 23:55:52 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>

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
};