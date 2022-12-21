/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:59:04 by wluong            #+#    #+#             */
/*   Updated: 2022/12/21 04:04:30 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wx_complex.hpp"

int main() {
	wx::Complex<int> yo(5, 7);
	wx::Complex<int> yo2(15, 4);
	std::cout << yo << std::endl;
	yo += 5;
	std::cout << yo << std::endl;
	yo *= yo2;
	yo = yo2;
	yo = yo + 5;
	std::cout << yo << std::endl;
	return 0;
}