/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:15:05 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:04 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stack)
{
	swap(&stack->last);
	ft_putstr_fd("sa\n", 1);
	return (SUCCESS);
}

int	sort(t_stack *stack)
{
	if (stack->size == 2)
		return (sa(stack));
	return (SUCCESS);
}
