/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:38:24 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 18:39:49 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnumber(char *number)
{
	while (*number)
	{
		if (!ft_isdigit(*number) && !is_white_space(*number))
			return (EXIT_FAILURE);
		number++;
	}
	return (EXIT_SUCCESS);
}

int	check_list_integer(char **numbers)
{
	unsigned int	i;

	i = 0;
	while (*(numbers + i) && **(numbers + i))
	{
		if (ft_isnumber(*(numbers + i)))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
