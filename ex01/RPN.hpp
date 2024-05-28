/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:28:09 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/29 00:33:33 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

class RPN
{
    public:
        RPN();
        RPN(const RPN &cpy);
        ~RPN();
        RPN &operator=(const RPN &rhs);
        void parse(std::string input);
        void calculate();
        void printResult();
    private:
        std::stack<char> _operation;
        std::stack<int> _numbers;
};