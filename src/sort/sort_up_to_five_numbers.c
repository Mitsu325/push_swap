/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_five_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:43:12 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/26 05:48:37 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_num_node(t_list *last)
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

void	move_smallest_number_to_top(t_stack *stack, int half_size)
{
	int	smallest_num_index;

	smallest_num_index = find_smallest_num_node(stack->last_a);
	if (smallest_num_index < half_size)
	{
		while (smallest_num_index != 0)
		{
			ra(stack);
			smallest_num_index--;
		}
		return ;
	}
	while (smallest_num_index != stack->size)
	{
		rra(stack);
		smallest_num_index++;
	}
}

void	push_smallest_number_to_b(t_stack *stack, int size_stack)
{
	int	size_stack_a;
	int	half_size;

	size_stack_a = stack->size;
	half_size = (stack->size / 2) + (stack->size % 2);
	while (size_stack_a > size_stack)
	{
		move_smallest_number_to_top(stack, half_size);
		pb(stack);
		size_stack_a--;
	}
}

void	push_smallest_number_to_a(t_stack *stack)
{
	while (stack->last_b != NULL)
		pa(stack);
}

int	sort_up_to_five_numbers(t_stack *stack)
{
	int	size_stack;

	size_stack = 3;
	push_smallest_number_to_b(stack, size_stack);
	sort_three_numbers(stack);
	push_smallest_number_to_a(stack);
	return (SUCCESS);
}
