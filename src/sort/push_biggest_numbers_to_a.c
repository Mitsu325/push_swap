/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_biggest_numbers_to_a.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:31:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:27:36 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_biggest_numbers_to_a(t_stack *stack)
{
	int		index;

	while (stack->last_b != NULL)
	{
		index = index_of_biggest_number(stack->last_b);
		if (index != 0)
			move_number_to_top_b(stack, index, stack->size_b);
		pa(stack);
	}
}
