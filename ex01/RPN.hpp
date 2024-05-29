/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:28:09 by bcarolle          #+#    #+#             */
/*   Updated: 2024/05/29 19:48:05 by bcarolle         ###   ########.fr       */
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
		std::stack<int> _numbers;
		void	reverseStack();
		void	doOperation(char c);
};
