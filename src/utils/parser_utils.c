/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 07:25:01 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:28:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_safe_parser(t_list **last, int status)
{
	if (status == FAILURE)
		ft_putstr_fd("Error\n", 2);
	ft_lstclear(last);
	exit(status);
}

int	clean_split(char **split, int status)
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
