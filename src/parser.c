/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:38:24 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 07:37:54 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_signal(int c)
{
	return (c == '+' || c == '-');
}

int	is_space(int c)
{
	return (c == SPC);
}

static int	is_number(char *number)
{
	while (*number)
	{
		if (!ft_isdigit(*number) && !is_space(*number) && !is_signal(*number))
			return (FAILURE);
		number++;
	}
	return (SUCCESS);
}

int	check_list_integer(char **numbers)
{
	unsigned int	i;

	i = 0;
	while (*(numbers + i) && **(numbers + i))
	{
		if (is_number(*(numbers + i)))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	is_integer(long int	number)
{
	if (number >= INT_MIN && number <= INT_MAX)
		return (SUCCESS);
	return (FAILURE);
}
