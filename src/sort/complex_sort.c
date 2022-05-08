/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:19:58 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/08 16:40:49 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: complex_sort
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Sort many numbers. First partition the stack a to determinate the pivot and
** push numbers less than the pivot to stack b. It then sorts the remaining
** numbers from the stack a, and finally pushes the numbers to stack a from the
** highest.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** Return 0 if successful.
** -------------------------------------------------------------------------- */
int	complex_sort(t_stack *stack)
{
	partition_a_and_push_b(stack);
	sort_number_remain_a(stack);
	push_biggest_numbers_to_a(stack);
	return (SUCCESS);
}
