/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 02:21:00 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 08:42:51 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	is_white_space(int c)
{
	if (c == SPC || (c >= TAB && c <= CR))
		return (1);
	return (0);
}

int	calculate_num(const char *str, int sign)
{
	int	num;

	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - 48);
		str++;
	}
	return (sign * num);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	is_first_sign;

	sign = 1;
	is_first_sign = 1;
	while (*str != '\0')
	{
		if (*str == '-' && is_first_sign)
		{
			sign = -1;
			is_first_sign = 0;
		}
		else if (*str == '+' && is_first_sign)
			is_first_sign = 0;
		else if (ft_isdigit(*str))
			return (calculate_num(str, sign));
		else if (!is_white_space(*str) && !is_first_sign)
			return (0);
		str++;
	}
	return (0);
}
