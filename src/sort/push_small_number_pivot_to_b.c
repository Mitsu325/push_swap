/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_small_number_pivot_to_b.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:13:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/08 17:27:32 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: index_of_small_num_pivot
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Get the index of the number smaller than the pivot. It loops throught the
** last and checks if the number is less than or equal to the pivot.
** PARAMETERS:
** #last. The t_list struct
** #pivot. The pivot number
** RETURN VALUES:
** Returns the index of the number less than or equal to the pivot. If there is
** no number in this condition, it returns -1.
** -------------------------------------------------------------------------- */
static int	index_of_small_num_pivot(t_list *last, int pivot)
{
	t_list	*temp;
	int		i;

	i = -1;
	temp = last->next;
	while (temp != last)
	{
		i++;
		if (temp->data <= pivot)
			return (i);
		temp = temp->next;
	}
	if (temp->data <= pivot)
	{
		i++;
		return (i);
	}
	return (-1);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: move_number_to_top
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Move the index number to the top with the least amount of operation.
** PARAMETERS:
** #stack. The t_stack struct
** #index. The index of the number that needs to be moved to the top
** #stack_size. The stack size
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
static void	move_number_to_top(t_stack *stack, int index, int stack_size)
{
	int	half_size;

	half_size = (stack_size / 2) + (stack_size % 2);
	if (index < half_size)
	{
		while (index != 0)
		{
			ra(stack);
			index--;
		}
		return ;
	}
	while (index != stack_size)
	{
		rra(stack);
		index++;
	}
}

/* -------------------------------------------------------------------------- **
** FUNCTION: push_small_number_pivot_to_b
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Partition the stack a to determinate the pivot and push numbers less than the
** pivot to stack b.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
void	push_small_number_pivot_to_b(t_stack *stack, int pivot)
{
	int	index;

	index = index_of_small_num_pivot(stack->last_a, pivot);
	while (index != -1)
	{
		if (index != 0)
			move_number_to_top(stack, index, stack->size_a);
		pb(stack);
		stack->size_b++;
		stack->size_a--;
		index = index_of_small_num_pivot(stack->last_a, pivot);
	}
}
