/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:57:05 by bcarolle          #+#    #+#             */
/*   Updated: 2024/06/01 02:05:36 by bcarolle         ###   ########.fr       */
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
        void    printPerf();
        void    sort();
    private:
        template <class Container>
        void    sortContainer(Container &content);
        std::vector<int> _vector;
        std::deque<int> _deque;
};