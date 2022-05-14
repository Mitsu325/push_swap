/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:36:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:26:39 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parser_save(char **argv, t_stack *stack)
{
	int	i;

	if (check_number(++argv))
		exit_safe_parser(&stack->last_a, FAILURE);
	i = 0;
	while (*(argv + i) && **(argv + i))
	{
		if (save_number(stack, *(argv + i)))
			exit_safe_parser(&stack->last_a, FAILURE);
		i++;
	}
	if (stack->last_a == NULL || check_sort(stack->last_a) == SUCCESS)
		exit_safe_parser(&stack->last_a, SUCCESS);
	stack->size_a = stack->full_size;
	return (SUCCESS);
}
