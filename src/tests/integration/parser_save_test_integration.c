/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save_test_integration.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:38:59 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 08:30:21 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_parser_save
{
	char	*argv[5];
	t_list	*last;
	int		result;
}		t_parser_save;

// static int	test_empty_string(void)
// {
// 	t_parser_save check;

// 	check.argv[0] = "./push_swap";
// 	check.argv[1] = " ";
// 	check.argv[2] = "\0";
// 	check.last = NULL;
// 	check.result = parser_save(check.argv, &check.last);
// 	if (check.result == FAILURE || check.result == SUCCESS)
// 	{
// 		return (print_status("parser_save", "test_empty_string",
// 		"Ensure exit if argv is string empty", FAILURE));
// 	}
// 	return (SUCCESS);
// }

// static int	test_one_number(void)
// {
// 	t_parser_save check;

// 	check.argv[0] = "./push_swap";
// 	check.argv[1] = "142";
// 	check.argv[2] = "\0";
// 	check.last = NULL;
// 	check.result = parser_save(check.argv, &check.last);
// 	if (check.result == FAILURE || check.result == SUCCESS)
// 	{
// 		return (print_status("parser_save", "test_one_number",
// 		"Ensure exit if argv is one number", FAILURE));
// 	}
// 	return (SUCCESS);
// }

static int	test_multiple_number(void)
{
	t_parser_save check;

	check.argv[0] = "./push_swap";
	check.argv[1] = "142";
	check.argv[2] = "2  -9";
	check.argv[3] = "+05";
	check.argv[4] = "\0";
	check.last = NULL;
	check.result = parser_save(check.argv, &check.last);
	// ft_putlst_fd(check.last, 1);
	ft_lstclear(&check.last);
	if (check.result == SUCCESS)
	{
		return (print_status("parser_save", "test_multiple_number", "OK",
		SUCCESS));
	}
	return (print_status("parser_save", "test_multiple_number",
	"Ensure returns 0 if save numbers", FAILURE));
}

// static int	test_sorted_number(void)
// {
// 	t_parser_save check;

// 	check.argv[0] = "./push_swap";
// 	check.argv[1] = "-142";
// 	check.argv[2] = "2  9";
// 	check.argv[3] = "+051";
// 	check.argv[4] = "\0";
// 	check.last = NULL;
// 	check.result = parser_save(check.argv, &check.last);
// 	// ft_putlst_fd(check.last, 1);
// 	// ft_lstclear(&check.last);
// 	if (check.result == FAILURE || check.result == SUCCESS)
// 	{
// 		return (print_status("parser_save", "test_sorted_number",
// 		"Ensure exit if argv is sorted number", FAILURE));
// 	}
// 	return (SUCCESS);
// }

int	parser_save_test_i(void)
{
	// if (test_empty_string())
	// 	return (FAILURE);
	// if (test_one_number())
	// 	return (FAILURE);
	if (test_multiple_number())
		return (FAILURE);
	// if (test_sorted_number())
	// 	return (FAILURE);
	return (SUCCESS);
}
