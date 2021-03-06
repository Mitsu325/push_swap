/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:38:24 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/06 06:46:14 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: is_number
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Check if the string contains only digits, space or sign.
** PARAMETERS:
** #numbers. The string
** RETURN VALUES:
** Return 0 if the string contains only numbers and 1 if the list contains
** other characters.
** -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- **
** FUNCTION: check_number
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Check if the string list contains only digits, space or sign.
** PARAMETERS:
** #numbers. The list of strings
** RETURN VALUES:
** Return 0 if the string list contains only numbers and 1 if the list contains
** other characters.
** -------------------------------------------------------------------------- */
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
