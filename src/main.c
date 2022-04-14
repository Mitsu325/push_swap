/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/14 06:27:07 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

int	parser_unit_test(char **argv)
{
	if (!strcmp(argv[1], "-tp"))
		return (parser_save_test());
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (EXIT_FAILURE);
	if (parser_unit_test(argv))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
