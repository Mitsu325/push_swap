/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 06:58:42 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/14 05:17:26 by pmitsuko         ###   ########.fr       */
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
		return (EXIT_SUCCESS);
	temp = (*last)->next;
	while (temp != *last)
	{
		if (temp->data == data)
			return (EXIT_FAILURE);
		temp = temp->next;
	}
	if (temp->data == data)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
			return (clean_split(split_num, EXIT_FAILURE));
		if (check_duplicate(last, data))
			return (clean_split(split_num, EXIT_FAILURE));
		if (ft_lstadd_back(last, data))
			return (clean_split(split_num, EXIT_FAILURE));
		i++;
	}
	return (clean_split(split_num, EXIT_SUCCESS));
}
