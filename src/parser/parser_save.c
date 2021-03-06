/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:36:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/06 07:27:23 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: parser_save
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Takes the argv parameter, checks if it is a number and if it is sorted. Also
** save the numbers in t_stack struct.
** PARAMETERS:
** #argv. The list of strings
** #stack. The t_stack struct
** RETURN VALUES:
** Return 0 if successful. The program exists if the numbers are sorted and
** in case of error before return.
** -------------------------------------------------------------------------- */
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
