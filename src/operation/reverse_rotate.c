/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:16:50 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: reverse_rotate
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Shift down all elements of last. The last elment becomes the first one.
** PARAMETERS:
** #last. The t_list struct.
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- **
** FUNCTION: rra
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Shift down all elements of last_a. The last elment becomes the first one.
** It must display "rra".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	rra(t_stack *stack)
{
	reverse_rotate(&stack->last_a);
	ft_putstr_fd("rra\n", 1);
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: rrb
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Shift down all elements of last_b. The last elment becomes the first one.
** It must display "rrb".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	rrb(t_stack *stack)
{
	reverse_rotate(&stack->last_b);
	ft_putstr_fd("rrb\n", 1);
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: rrr
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** rra and rrb at the same time. It must display "rrr".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	rrr(t_stack *stack)
{
	reverse_rotate(&stack->last_a);
	reverse_rotate(&stack->last_b);
	ft_putstr_fd("rrr\n", 1);
	return (SUCCESS);
}
