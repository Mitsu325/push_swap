/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:38:24 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:26:26 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str) && !ft_issignal(*str))
			return (FAILURE);
		str++;
	}
	return (SUCCESS);
}

int	check_number(char **argv)
{
	unsigned int	i;

	i = 0;
	while (*(argv + i) && **(argv + i))
	{
		if (is_number(*(argv + i)))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
