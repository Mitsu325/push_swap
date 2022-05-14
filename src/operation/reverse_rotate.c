/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:25:46 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **last)
{
	t_list	*temp;

	if (*last == NULL || *last == (*last)->next)
		return ;
	temp = *last;
	while (temp->next != *last)
		temp = temp->next;
	*last = temp;
}

int	rra(t_stack *stack)
{
	reverse_rotate(&stack->last_a);
	ft_putstr_fd("rra\n", 1);
	return (SUCCESS);
}

int	rrb(t_stack *stack)
{
	reverse_rotate(&stack->last_b);
	ft_putstr_fd("rrb\n", 1);
	return (SUCCESS);
}

int	rrr(t_stack *stack)
{
	reverse_rotate(&stack->last_a);
	reverse_rotate(&stack->last_b);
	ft_putstr_fd("rrr\n", 1);
	return (SUCCESS);
}
