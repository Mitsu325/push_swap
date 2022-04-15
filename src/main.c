/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 23:59:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 14:08:11 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "test.h"

int	parser_test(char **argv)
{
	if (!strcmp(argv[1], "-tp"))
		return (parser_save_test());
	if (!strcmp(argv[1], "-ti"))
		return (parser_save_test_i());
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_list	*last;

	if (argc < 2)
		return (FAILURE);
	if (parser_test(argv))
		return (FAILURE);
	last = NULL;
	parser_save(argv, &last);
	ft_lstclear(&last);
	return (SUCCESS);
}
