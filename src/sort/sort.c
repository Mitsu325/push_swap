/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:15:05 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/24 18:37:06 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	}
	else
	{
		while (smallest_num_index != stack->size)
		{
			rra(stack);
			smallest_num_index++;
		}
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
	t_list	*temp;

	temp = stack->last_b;
	if (temp == temp->next)
		pa(stack);
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

int	sort(t_stack *stack)
{
	if (stack->size == 2)
		return (sa(stack));
	if (stack->size == 3)
		return (sort_three_numbers(stack));
	if (stack->size <= 5)
		return (sort_up_to_five_numbers(stack));
	return (SUCCESS);
}
