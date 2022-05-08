/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 05:57:01 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/06 05:58:56 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: init_stack
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Initialize the t_stack struct.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
void	init_stack(t_stack *stack)
{
	stack->last_a = NULL;
	stack->last_b = NULL;
	stack->full_size = 0;
	stack->size_a = 0;
	stack->size_b = 0;
}

/* -------------------------------------------------------------------------- **
** FUNCTION: exit_safe_stack
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Free all memory allocated within t_stack struct.
** PARAMETERS:
** #stack. The t_stack struct
** #status. The return number
** RETURN VALUES:
** Return the status number.
** -------------------------------------------------------------------------- */
int	exit_safe_stack(t_stack *stack, int status)
{
	ft_lstclear(&stack->last_a);
	ft_lstclear(&stack->last_b);
	return (status);
}
