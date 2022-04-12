/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 06:58:42 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/12 06:45:22 by pmitsuko         ###   ########.fr       */
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
		if (ft_lstadd_back(last, data))
			return (clean_split(split_num, EXIT_FAILURE));
		i++;
	}
	return (clean_split(split_num, EXIT_SUCCESS));
}
