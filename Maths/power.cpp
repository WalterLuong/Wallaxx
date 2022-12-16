/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:15:03 by wluong            #+#    #+#             */
/*   Updated: 2022/12/16 08:24:15 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wx_math.h"

double	wx::power(double number, int pow) {
	double final_value = number;
	if (pow == 0)
		return 1;
	for (int i = 1; i < wx::absolute(pow); i++) {
		final_value *= number;
	}
	return pow < 0 ? (1 / final_value) : final_value;
}
