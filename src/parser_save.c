/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:36:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 11:42:50 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	exit_safe(t_list **last, int status)
{
	if (status == FAILURE)
		ft_putstr_fd("Error\n", 1);
	ft_lstclear(last);
	exit(status);
}

int	parser_save(char **argv, t_list **last)
{
	int	i;

	if (check_list_integer(++argv))
		exit_safe(last, FAILURE);
	i = 0;
	while (*(argv + i) && **(argv + i))
	{
		if (save(last, *(argv + i)))
			return (FAILURE);
		i++;
	}
	if (*last == NULL || check_sort(*last) == SUCCESS)
		exit_safe(last, SUCCESS);
	return (SUCCESS);
}
