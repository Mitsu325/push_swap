/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 06:58:42 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 07:37:54 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	clean_split(char **split, int status)
{
	int	i;

	i = 0;
	while (*(split + i))
	{
		free(*(split + i));
		i++;
	}
	free(split);
	return (status);
}

int	check_duplicate(t_list **last, long int data)
{
	t_list	*temp;

	if (*last == NULL || *last == (*last)->next)
		return (SUCCESS);
	temp = (*last)->next;
	while (temp != *last)
	{
		if (temp->data == data)
			return (FAILURE);
		temp = temp->next;
	}
	if (temp->data == data)
		return (FAILURE);
	return (SUCCESS);
}

int	save(t_list **last, char *number)
{
	long int	data;
	char		**split_num;
	int			i;

	split_num = ft_split(number, ' ');
	i = 0;
	while (*(split_num + i))
	{
		data = ft_atoi(*(split_num + i));
		if (is_integer(data))
			return (clean_split(split_num, FAILURE));
		if (check_duplicate(last, data))
			return (clean_split(split_num, FAILURE));
		if (ft_lstadd_back(last, data))
			return (clean_split(split_num, FAILURE));
		i++;
	}
	return (clean_split(split_num, SUCCESS));
}
