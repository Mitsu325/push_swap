/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/18 06:16:50 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **last)
{
	t_list	*head;
	t_list	*temp;

	if (*last == NULL || *last == (*last)->next)
		return ;
	head = (*last)->next;
	temp = head->next->next;
	(*last)->next = head->next;
	head->next->next = head;
	head->next = temp;
}
