/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/01 09:59:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(t_list **last)
{
	t_list	*head;
	t_list	*temp;

	if (*last == NULL || *last == (*last)->next)
		return ;
	if (*last == (*last)->next->next)
	{
		*last = (*last)->next;
		return ;
	}
	head = (*last)->next;
	temp = head->next->next;
	(*last)->next = head->next;
	head->next->next = head;
	head->next = temp;
}

int	sa(t_stack *stack)
{
	swap(&stack->last_a);
	ft_putstr_fd("sa\n", 1);
	return (SUCCESS);
}

int	sb(t_stack *stack)
{
	swap(&stack->last_b);
	ft_putstr_fd("sb\n", 1);
	return (SUCCESS);
}

int	ss(t_stack *stack)
{
	swap(&stack->last_a);
	swap(&stack->last_b);
	ft_putstr_fd("ss\n", 1);
	return (SUCCESS);
}
