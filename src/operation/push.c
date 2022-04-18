/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/18 07:35:11 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	insert_first_node(t_list **last, t_list *node)
{
	if (*last == NULL)
	{
		node->next = node;
		*last = node;
	}
	else
	{
		node->next = (*last)->next;
		(*last)->next = node;
	}
}

void	push(t_list **last_to, t_list **last_from)
{
	t_list	*first;

	if (*last_from == NULL)
		return ;
	first = remove_first_node(last_from);
	insert_first_node(last_to, first);
}
