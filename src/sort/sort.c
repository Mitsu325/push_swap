/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:15:05 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/22 05:40:52 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three_numbers(t_stack *stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = stack->last->next;
	second = stack->last->next->next;
	third = stack->last;
	if (second->data > third->data)
	{
		if (first->data < second->data && first->data > third->data)
			return (rra(stack));
		sa(stack);
		if (first->data < second->data)
			return (ra(stack));
		else
			return (rra(stack));
	}
	else if (first->data < third->data)
		return (sa(stack));
	return (ra(stack));
}

int	sort(t_stack *stack)
{
	if (stack->size == 2)
		return (sa(stack));
	if (stack->size == 3)
		return (sort_three_numbers(stack));
	return (SUCCESS);
}
