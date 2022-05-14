/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:17:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: swap
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Swap the first 2 elements at the top of list. Do nothing if there is only
** one or no elements.
** PARAMETERS:
** #last. The t_list struct.
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
static void	swap(t_list **last)
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

/* -------------------------------------------------------------------------- **
** FUNCTION: sa
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Swap the first 2 elements at the top of last_a. It must display "sa".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	sa(t_stack *stack)
{
	swap(&stack->last_a);
	ft_putstr_fd("sa\n", 1);
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: sb
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Swap the first 2 elements at the top of last_b. It must display "sb".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	sb(t_stack *stack)
{
	swap(&stack->last_b);
	ft_putstr_fd("sb\n", 1);
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: ss
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** sa and sb at the same time. It must display "ss".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	ss(t_stack *stack)
{
	swap(&stack->last_a);
	swap(&stack->last_b);
	ft_putstr_fd("ss\n", 1);
	return (SUCCESS);
}
