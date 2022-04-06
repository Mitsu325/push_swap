/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 06:32:18 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

int	check_list_integer(char **numbers)
{
	while (*numbers && **numbers)
	{
		if (!ft_isdigit(**numbers))
			return (EXIT_FAILURE);
		numbers++;
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
