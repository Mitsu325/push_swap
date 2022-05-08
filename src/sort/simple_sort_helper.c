/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 09:48:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/08 16:13:52 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: find_smallest_num_node
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Find the smallest number in t_list struct.
** PARAMETERS:
** #last. The t_list struct
** RETURN VALUES:
** Return the index of the smallest number.
** -------------------------------------------------------------------------- */
int	find_smallest_num_node(t_list *last) // TODO: convert function to static before remove tester
{
	t_list	*temp;
	int		min;
	int		i;
	int		smallest_num_index;

	i = 0;
	smallest_num_index = 0;
	temp = last->next;
	min = temp->data;
	while (temp != last)
	{
		i++;
		if (min > temp->next->data)
		{
			min = temp->next->data;
			smallest_num_index = i;
		}
		temp = temp->next;
	}
	return (smallest_num_index);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: move_smallest_number_to_top
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Moves the smallest number to the top of the stack. First find the index of
** the smallest number to choose the smallest operation.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
static void	move_smallest_number_to_top(t_stack *stack)
{
	int	smallest_num_index;
	int	half_size;

	smallest_num_index = find_smallest_num_node(stack->last_a);
	if (smallest_num_index == 1)
	{
		sa(stack);
		return ;
	}
	half_size = (stack->size_a / 2) + (stack->size_a % 2);
	if (smallest_num_index < half_size)
	{
		while (smallest_num_index != 0)
		{
			ra(stack);
			smallest_num_index--;
		}
		return ;
	}
	while (smallest_num_index != stack->size_a)
	{
		rra(stack);
		smallest_num_index++;
	}
}

/* -------------------------------------------------------------------------- **
** FUNCTION: push_smallest_number_to_b
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Push the smallest numbers to stack b. First the smallest number is moved to
** the top of the stack and then pushed to b. The process is repeated until the
** size of stack a is equal to size_stack.
** PARAMETERS:
** #stack. The t_stack struct
** #size_stack. Size the stack a should be at the end of the process
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
void	push_smallest_number_to_b(t_stack *stack, int size_stack)
{
	while (stack->size_a > size_stack)
	{
		move_smallest_number_to_top(stack);
		pb(stack);
		stack->size_a--;
	}
}

/* -------------------------------------------------------------------------- **
** FUNCTION: push_number_to_a
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Push the numbers to the stack a by the amount of num_pushed.
** PARAMETERS:
** #stack. The t_stack struct
** #num_pushed. The number of nodes pushed
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
void	push_number_to_a(t_stack *stack, int num_pushed)
{
	while (num_pushed)
	{
		pa(stack);
		num_pushed--;
	}
}
