/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:36:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/26 12:26:48 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	exit_safe(t_list **last, int status)
{
	if (status == FAILURE)
		ft_putstr_fd("Error\n", 1);
	ft_lstclear(last);
	exit(status);
}

int	parser_save(char **argv, t_stack *stack)
{
	int	i;

	if (check_number(++argv))
		exit_safe(&stack->last_a, FAILURE);
	i = 0;
	while (*(argv + i) && **(argv + i))
	{
		if (save_number(stack, *(argv + i)))
			exit_safe(&stack->last_a, FAILURE);
		i++;
	}
	if (stack->last_a == NULL || check_sort(stack->last_a) == SUCCESS)
		exit_safe(&stack->last_a, SUCCESS);
	stack->size_a = stack->full_size;
	return (SUCCESS);
}
