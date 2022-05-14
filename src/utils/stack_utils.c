/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 05:57:01 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:28:52 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->last_a = NULL;
	stack->last_b = NULL;
	stack->full_size = 0;
	stack->size_a = 0;
	stack->size_b = 0;
}

int	exit_safe_stack(t_stack *stack, int status)
{
	ft_lstclear(&stack->last_a);
	ft_lstclear(&stack->last_b);
	return (status);
}
