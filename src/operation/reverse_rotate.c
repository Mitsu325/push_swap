/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/22 05:33:23 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	reverse_rotate(t_list **last)
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
	reverse_rotate(&stack->last);
	ft_putstr_fd("rra\n", 1);
	return (SUCCESS);
}
