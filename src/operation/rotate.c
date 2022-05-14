/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:25:58 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **last)
{
	if (*last == NULL || *last == (*last)->next)
		return ;
	*last = (*last)->next;
}

int	ra(t_stack *stack)
{
	rotate(&stack->last_a);
	ft_putstr_fd("ra\n", 1);
	return (SUCCESS);
}

int	rb(t_stack *stack)
{
	rotate(&stack->last_b);
	ft_putstr_fd("rb\n", 1);
	return (SUCCESS);
}

int	rr(t_stack *stack)
{
	rotate(&stack->last_a);
	rotate(&stack->last_b);
	ft_putstr_fd("rr\n", 1);
	return (SUCCESS);
}
