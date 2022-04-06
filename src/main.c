/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 04:48:05 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list_integer(char **numbers)
{
	// while (*numbers)
	// {
	// 	if (!ft_isdigit('0'))
	// 		return (EXIT_FAILURE);
	// 	numbers++;
	// }
	int num = ft_atoi(*numbers);
	return (num);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (EXIT_FAILURE);
	printf("%s\n", argv[1]);
	return (EXIT_SUCCESS);
}
