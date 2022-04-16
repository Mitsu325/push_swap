/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 06:58:42 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/16 16:46:06 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: include static after remove tests
int	is_integer(long int number)
{
	if (number >= INT_MIN && number <= INT_MAX)
		return (SUCCESS);
	return (FAILURE);
}

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

static int	check_duplicate(t_list **last, long int data)
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

int	save_number(t_stack *stack, char *number)
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
		if (check_duplicate(&stack->last, data))
			return (clean_split(split_num, FAILURE));
		if (ft_lstadd_back(&stack->last, data))
			return (clean_split(split_num, FAILURE));
		i++;
	}
	stack->size += i;
	return (clean_split(split_num, SUCCESS));
}