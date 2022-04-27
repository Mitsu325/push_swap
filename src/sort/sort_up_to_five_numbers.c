/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_five_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:43:12 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/27 07:06:51 by pmitsuko         ###   ########.fr       */
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

void	move_smallest_number_to_top(t_stack *stack)
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

void	push_smallest_number_to_b(t_stack *stack, int size_stack)
{
	while (stack->size_a > size_stack)
	{
		move_smallest_number_to_top(stack);
		pb(stack);
		stack->size_a--;
	}
}

void	push_smallest_number_to_a(t_stack *stack, int num_pushed_b)
{
	while (num_pushed_b)
	{
		pa(stack);
		num_pushed_b--;
	}
}

int	sort_up_to_five_numbers(t_stack *stack)
{
	int	size_stack;
	int	num_pushed_b;

	size_stack = 3;
	num_pushed_b = stack->size_a - size_stack;
	push_smallest_number_to_b(stack, size_stack);
	if (check_sort(stack->last_a))
		sort_three_numbers(stack);
	push_smallest_number_to_a(stack, num_pushed_b);
	return (SUCCESS);
}

int	sort_up_to_ten_numbers(t_stack *stack)
{
	int	size_stack;
	int	num_pushed_b;

	size_stack = 5;
	num_pushed_b = stack->size_a - size_stack;
	push_smallest_number_to_b(stack, size_stack);
	sort_up_to_five_numbers(stack);
	push_smallest_number_to_a(stack, num_pushed_b);
	return (SUCCESS);
}
