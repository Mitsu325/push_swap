/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:15:05 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/08 16:41:34 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: sort
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Sort the stack by stack size.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** Return 0 if successful.
** -------------------------------------------------------------------------- */
int	sort(t_stack *stack)
{
	if (stack->full_size == 2)
		return (sa(stack));
	if (stack->full_size == 3)
		return (sort_three_numbers(stack));
	if (stack->full_size <= 5)
		return (sort_up_to_five_numbers(stack));
	if (stack->full_size <= 10)
		return (sort_up_to_ten_numbers(stack));
	else
		return (complex_sort(stack));
	return (SUCCESS);
}
