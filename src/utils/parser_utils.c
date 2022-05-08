/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 07:25:01 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/06 07:31:38 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: exit_safe_parser
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Free all memory allocated within t_list struct. In case the status is 1,
** it must display "Error".
** PARAMETERS:
** #last. The t_list struct
** #status. The return number
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
void	exit_safe_parser(t_list **last, int status)
{
	if (status == FAILURE)
		ft_putstr_fd("Error\n", 2);
	ft_lstclear(last);
	exit(status);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: clean_split
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Free all memory allocated within split.
** PARAMETERS:
** #split. The list of strings
** #status. The return number
** RETURN VALUES:
** Return status number.
** -------------------------------------------------------------------------- */
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
