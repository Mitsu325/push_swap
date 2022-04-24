/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:42:11 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/24 18:42:31 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
