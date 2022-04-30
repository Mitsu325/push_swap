/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/30 17:05:15 by pmitsuko         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc < 2)
		return (FAILURE);
	if (parser_test(argv))
		return (FAILURE);
	stack.last_a = NULL;
	stack.last_b = NULL;
	stack.full_size = 0;
	stack.size_a = 0;
	stack.size_b = 0;
	parser_save(argv, &stack);
	ft_lstclear(&stack.last_a);
	ft_lstclear(&stack.last_b);
	return (SUCCESS);
}
