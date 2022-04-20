/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/20 05:39:51 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static t_list	*remove_first_node(t_list **last)
{
	t_list	*first;

	first = (*last)->next;
	if (*last == (*last)->next)
		*last = NULL;
	else
		(*last)->next = (*last)->next->next;
	return first;
}

void	rotate(t_list **last)
{
	t_list	*temp;

	if (*last == NULL || *last == (*last)->next)
		return ;
	temp = remove_first_node(last);
	temp->next = (*last)->next;
	(*last)->next = temp;
	*last = temp;
}
