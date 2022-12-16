/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wx_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluong <wluong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 07:15:44 by wluong            #+#    #+#             */
/*   Updated: 2022/12/16 08:25:15 by wluong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WX_MATH_H
#define WX_MATH_H

# include <type_traits>
# include <iostream>

namespace wx {
	double	absolute(double number);
	double	power(double number, int pow);
	double	sqrt(double number);
}

#endif