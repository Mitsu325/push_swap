/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_small_number_pivot_to_b.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:13:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:27:45 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_small_number_pivot_to_b(t_stack *stack, t_pivot pivot)
{
	int		index;

	index = index_of_small_num_pivot(stack->last_a, pivot.num);
	while (index != -1)
	{
		if (index != 0)
		{
			if (stack->size_b > 1 && stack->last_b->next->data < pivot.half)
				rr(stack);
			else
				ra(stack);
		}
		if (stack->last_a->next->data <= pivot.num)
			pb(stack);
		index = index_of_small_num_pivot(stack->last_a, pivot.num);
	}
}
