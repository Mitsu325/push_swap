/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:16:59 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: rotate
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Shift up all elements of last. The first element becomes the last one.
** PARAMETERS:
** #last. The t_list struct.
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
static void	rotate(t_list **last)
{
	if (*last == NULL || *last == (*last)->next)
		return ;
	*last = (*last)->next;
}

/* -------------------------------------------------------------------------- **
** FUNCTION: ra
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Shift up all elements of last_a. It must display "ra".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	ra(t_stack *stack)
{
	rotate(&stack->last_a);
	ft_putstr_fd("ra\n", 1);
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: rb
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Shift up all elements of last_b. It must display "rb".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	rb(t_stack *stack)
{
	rotate(&stack->last_b);
	ft_putstr_fd("rb\n", 1);
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: rr
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** ra and rb at the same time. It must display "rr".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	rr(t_stack *stack)
{
	rotate(&stack->last_a);
	rotate(&stack->last_b);
	ft_putstr_fd("rr\n", 1);
	return (SUCCESS);
}
