/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/06 05:45:51 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

int	parser_test(char **argv)
{
	if (!strcmp(argv[1], "-tp"))
		exit(parser_save_test());
	if (!strcmp(argv[1], "-to"))
		exit(operation_test());
	if (!strcmp(argv[1], "-ti"))
		exit(parser_save_test_i());
	if (!strcmp(argv[1], "-ts"))
		exit(sort_test());
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** push_swap
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** This project sorts the data into an integer stack and sorts with a limited
** operations using only two stacks. The execution of the program starts with
** initialization of the t_stack struct and will receive the argv, parse it
** into a t_stack struct and sort it appropriately.
** -------------------------------------------------------------------------- */
int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (FAILURE);
	if (parser_test(argv))
		return (FAILURE);
	init_stack(&stack);
	parser_save(argv, &stack);
	sort(&stack);
	return (exit_safe_stack(&stack, SUCCESS));
}
