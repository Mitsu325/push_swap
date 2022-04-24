/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/24 18:09:26 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*remove_first_node(t_list **last)
{
	t_list	*first;

	first = (*last)->next;
	if (*last == (*last)->next)
		*last = NULL;
	else
		(*last)->next = (*last)->next->next;
	return (first);
}

static void	insert_first_node(t_list **last, t_list *node)
{
	if (*last == NULL)
	{
		node->next = node;
		*last = node;
	}
	else
	{
		node->next = (*last)->next;
		(*last)->next = node;
	}
}

void	push(t_list **last_to, t_list **last_from)
{
	t_list	*first;

	if (*last_from == NULL)
		return ;
	first = remove_first_node(last_from);
	insert_first_node(last_to, first);
}

int	pa(t_stack *stack)
{
	push(&stack->last_a, &stack->last_b);
	ft_putstr_fd("pa\n", 1);
	return (SUCCESS);
}

int	pb(t_stack *stack)
{
	push(&stack->last_b, &stack->last_a);
	ft_putstr_fd("pb\n", 1);
	return (SUCCESS);
}
