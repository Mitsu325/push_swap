/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:47:15 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/08 17:48:00 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: sort_three_numbers
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Sort three stack numbers.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** Return 0 if successful.
** -------------------------------------------------------------------------- */
int	sort_three_numbers(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = stack->last_a->next;
	second = stack->last_a->next->next;
	third = stack->last_a;
	if (second->data > third->data)
	{
		if (first->data < second->data && first->data > third->data)
			return (rra(stack));
		sa(stack);
		if (first->data < second->data)
			return (ra(stack));
		return (rra(stack));
	}
	else if (first->data < third->data)
		return (sa(stack));
	return (ra(stack));
}

/* -------------------------------------------------------------------------- **
** FUNCTION: sort_up_to_five_numbers
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Sorts up to five numbers. Push the smallest numbers to stack b until only
** three numbers remain in a, sorts the three numbers from stack a, and finally
** pushes the numbers from stack b to stack a.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** Return 0 if successful.
** -------------------------------------------------------------------------- */
int	sort_up_to_five_numbers(t_stack *stack)
{
	int	size_stack;
	int	num_pushed_b;

	size_stack = 3;
	num_pushed_b = stack->size_a - size_stack;
	push_smallest_number_to_b(stack, size_stack);
	if (check_sort(stack->last_a))
		sort_three_numbers(stack);
	push_number_to_a(stack, num_pushed_b);
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: sort_up_to_ten_numbers
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Sorts up to ten numbers. First push the smallest numbers to stack b until
** only five numbers remain in a, sorts the five numbers from stack a, and
** finally pushes the numbers from stack b to stack a.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** Return 0 if successful.
** -------------------------------------------------------------------------- */
int	sort_up_to_ten_numbers(t_stack *stack)
{
	int	size_stack;
	int	num_pushed_b;

	size_stack = 5;
	num_pushed_b = stack->size_a - size_stack;
	push_smallest_number_to_b(stack, size_stack);
	sort_up_to_five_numbers(stack);
	push_number_to_a(stack, num_pushed_b);
	return (SUCCESS);
}
