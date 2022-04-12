/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 06:58:42 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/12 05:45:16 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	save(t_list **last, char *number)
{
	char	**split_num;
	int		data;
	int		i;

	split_num = ft_split(number, ' ');
	i = 0;
	while (*(split_num + i))
	{
		data = ft_atoi(*(split_num + i));
		if (ft_lstadd_back(last, data))
			return (EXIT_FAILURE);
		free(*(split_num + i));
		i++;
	}
	free(split_num);
	return (EXIT_SUCCESS);
}
