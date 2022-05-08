/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_biggest_numbers_to_a.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:31:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/08 17:40:21 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: index_of_biggest_number
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Get the index of the biggest number in the list
** PARAMETERS:
** #last. The t_list struct
** RETURN VALUES:
** Returns the index of the biggest number in the list.
** -------------------------------------------------------------------------- */
static int	index_of_biggest_number(t_list *last)
{
	t_list	*temp;
	int		max;
	int		i;
	int		bigger_number_index;

	i = 0;
	bigger_number_index = i;
	temp = last->next;
	max = temp->data;
	while (temp != last)
	{
		i++;
		if (max < temp->next->data)
		{
			max = temp->next->data;
			bigger_number_index = i;
		}
		temp = temp->next;
	}
	return (bigger_number_index);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: move_number_to_top_b
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Move the index number to the top of stack b with the least amount of
** operation.
** PARAMETERS:
** #stack. The t_stack struct
** #index. The index of the number that needs to be moved to the top
** #stack_size. The stack size
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
static void	move_number_to_top_b(t_stack *stack, int index, int stack_size)
{
	int	half_size;

	if (index == 1)
	{
		sb(stack);
		return ;
	}
	half_size = (stack_size / 2) + (stack_size % 2);
	if (index < half_size)
	{
		while (index != 0)
		{
			rb(stack);
			index--;
		}
		return ;
	}
	while (index != stack_size)
	{
		rrb(stack);
		index++;
	}
}

/* -------------------------------------------------------------------------- **
** FUNCTION: push_biggest_numbers_to_a
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Push numbers to stack a from largest to smallest until stack b empty.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
void	push_biggest_numbers_to_a(t_stack *stack)
{
	int		index;

	while (stack->last_b != NULL)
	{
		index = index_of_biggest_number(stack->last_b);
		if (index != 0)
			move_number_to_top_b(stack, index, stack->size_b);
		pa(stack);
		stack->size_a++;
		stack->size_b--;
	}
}
