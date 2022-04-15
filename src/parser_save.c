/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:36:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 07:50:05 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	parser_save(char **argv, t_list **last)
{
	int	i;

	if (check_list_integer(++argv))
		return (FAILURE);
	i = 0;
	while (*(argv + i) && **(argv + i))
	{
		if (save(last, *(argv + i)))
			return (FAILURE);
		i++;
	}
	if (*last == NULL || *last == (*last)->next)
		exit(SUCCESS);
	return (SUCCESS);
}
