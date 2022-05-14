/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:29:00 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
