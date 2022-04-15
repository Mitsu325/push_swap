/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:53:45 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 21:59:34 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *last)
{
	t_list	*current;

	if (last == NULL)
		return (FAILURE);
	current = last->next;
	if (last == current)
		return (SUCCESS);
	while (current != last)
	{
		if (current->data > current->next->data)
			return (FAILURE);
		current = current->next;
	}
	return (SUCCESS);
}
