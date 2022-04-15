/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:58:36 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 17:13:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **last)
{
	t_list	*temp;
	t_list	*current;

	if (*last == NULL)
		return ;
	current = (*last)->next;
	while (current != *last)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(*last);
	*last = NULL;
}
