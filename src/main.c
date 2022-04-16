/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/16 13:20:48 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

int	parser_test(char **argv)
{
	if (!strcmp(argv[1], "-tp"))
		exit(parser_save_test());
	if (!strcmp(argv[1], "-ti"))
		exit(parser_save_test_i());
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (FAILURE);
	if (parser_test(argv))
		return (FAILURE);
	stack.last = NULL;
	stack.size = 0;
	parser_save(argv, &stack);
	ft_putlst_fd(stack.last, 1);
	ft_lstclear(&stack.last);
	return (SUCCESS);
}
