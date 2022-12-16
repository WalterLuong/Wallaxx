/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqrt.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:24:37 by wluong            #+#    #+#             */
/*   Updated: 2022/12/16 08:27:20 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wx_math.h"

double wx::sqrt(double number) {
	double	temp, result;
	double	inp_y;

	inp_y = number;
	result = inp_y / 2;
	temp = 0;
	while(result != temp) {
		temp = result;
		result = ( inp_y/temp + temp) / 2;
	}
	return (result);
}
