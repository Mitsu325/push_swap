/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:53:45 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/12 07:28:10 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list *last)
{
	t_list *current;

	if (last == NULL)
			return (EXIT_FAILURE);
	current = last->next;
	if (last == current)
		return (EXIT_SUCCESS);
	while (current != last)
	{
		if (current->data >= current->next->data)
			return (EXIT_FAILURE);
		current = current->next;
	}
	return (EXIT_SUCCESS);
}
