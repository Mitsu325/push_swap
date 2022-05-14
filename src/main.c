/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:10:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	init_stack(&stack);
	parser_save(argv, &stack);
	sort(&stack);
	return (exit_safe_stack(&stack, SUCCESS));
}
