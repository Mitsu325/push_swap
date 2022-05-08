/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:53:45 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/06 07:13:20 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: check_sort
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Checks if the list is sorted in ascending order.
** PARAMETERS:
** #last. The t_list struct
** RETURN VALUES:
** Return 0 if the list is in ascending order and 1 if not.
** -------------------------------------------------------------------------- */
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
