/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_number_remain_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:28:38 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/08 17:52:19 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: sort_number_remain_a
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Sort the remaining numbers from the stack a.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
void	sort_number_remain_a(t_stack *stack)
{
	int	size_stack;
	int	num_pushed_b;

	size_stack = 3;
	num_pushed_b = stack->size_a - size_stack;
	push_smallest_number_to_b(stack, size_stack);
	if (check_sort(stack->last_a))
		sort_three_numbers(stack);
	push_number_to_a(stack, num_pushed_b);
}
