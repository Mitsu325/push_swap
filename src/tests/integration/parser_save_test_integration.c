/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save_test_integration.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:38:59 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 07:26:18 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_parser_save
{
	char	*argv[5];
	t_list	*last;
	int		result;
}		t_parser_save;

static int	test_empty_string(void)
{
	t_parser_save check;

	check.argv[0] = "./push_swap";
	check.argv[1] = " ";
	check.argv[2] = "\0";
	check.last = NULL;
	check.result = parser_save(check.argv, &check.last);
	if (check.result == EXIT_FAILURE || check.result == EXIT_SUCCESS)
	{
		return (print_status("parser_save", "test_empty_string",
		"Ensure exit if argv is string empty", EXIT_FAILURE));
	}
	return (EXIT_SUCCESS);
}

int	parser_save_test_i(void)
{
	if (test_empty_string())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
