/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 08:49:03 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

int	ft_isnumber(char *number)
{
	while (*number)
	{
		if (!ft_isdigit(*number) && !is_white_space(*number))
			return (EXIT_FAILURE);
		number++;
	}
	return (EXIT_SUCCESS);
}

int	check_list_integer(char **numbers)
{
	unsigned int	i;

	i = 0;
	while (*(numbers + i) && **(numbers + i))
	{
		if (ft_isnumber(*(numbers + i)))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (push_swap_test())
		return (EXIT_FAILURE);
	if (argc < 2)
		return (EXIT_FAILURE);
	printf("%s\n", argv[1]);
	return (EXIT_SUCCESS);
}
