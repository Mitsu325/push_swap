/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:58:36 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/09 17:56:35 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back(t_list **last_node, int data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (EXIT_FAILURE);
	new_node->data = data;
	if (*last_node == NULL)
		new_node->next = new_node;
	else
	{
		new_node->next = (*last_node)->next;
		(*last_node)->next = new_node;
	}
	*last_node = new_node;
	return (EXIT_SUCCESS);
}
