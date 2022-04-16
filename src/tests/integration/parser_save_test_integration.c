/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save_test_integration.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 06:38:59 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/16 16:39:23 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_parser_save
{
	char	*argv[5];
	t_stack	stack;
	int		result;
}		t_parser_save;

// static int	test_empty_string(void)
// {
// 	t_parser_save check;

// 	check.argv[0] = "./push_swap";
// 	check.argv[1] = " ";
// 	check.argv[2] = "\0";
// 	check.stack.last = NULL;
// 	check.stack.size = 0;
// 	check.result = parser_save(check.argv, &check.stack);
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
// 	check.stack.last = NULL;
// 	check.stack.size = 0;
// 	check.result = parser_save(check.argv, &check.stack);
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
	check.stack.last = NULL;
	check.stack.size = 0;
	check.result = parser_save(check.argv, &check.stack);
	ft_putlst_fd(check.stack.last, 1);
	ft_lstclear(&check.stack.last);
	if (check.result == SUCCESS)
	{
		return (print_status("parser_save", "test_multiple_number", "OK",
		SUCCESS));
	}
	return (print_status("parser_save", "test_multiple_number",
	"Ensure returns 0 if save numbers", FAILURE));
}

static int	test_multiple_number_with_space(void)
{
	t_parser_save check;

	check.argv[0] = "./push_swap";
	check.argv[1] = "142";
	check.argv[2] = "16  9   6";
	check.argv[3] = "+05";
	check.argv[4] = "\0";
	check.stack.last = NULL;
	check.stack.size = 0;
	check.result = parser_save(check.argv, &check.stack);
	ft_putlst_fd(check.stack.last, 1);
	ft_lstclear(&check.stack.last);
	if (check.result == SUCCESS)
	{
		return (print_status("parser_save", "test_multiple_number_with_space",
		"OK", SUCCESS));
	}
	return (print_status("parser_save", "test_multiple_number_with_space",
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
// 	check.stack.last = NULL;
// 	check.stack.size = 0;
// 	check.result = parser_save(check.argv, &check.stack);
// 	// ft_putlst_fd(check.last, 1);
// 	// ft_lstclear(&check.last);
// 	if (check.result == FAILURE || check.result == SUCCESS)
// 	{
// 		return (print_status("parser_save", "test_sorted_number",
// 		"Ensure exit if argv is sorted number", FAILURE));
// 	}
// 	return (SUCCESS);
// }

// static int	test_no_int(void)
// {
// 	t_parser_save check;

// 	check.argv[0] = "./push_swap";
// 	check.argv[1] = "142";
// 	check.argv[2] = "one  23";
// 	check.argv[3] = "2";
// 	check.argv[4] = "\0";
// 	check.stack.last = NULL;
// 	check.stack.size = 0;
// 	check.result = parser_save(check.argv, &check.stack);
// 	ft_lstclear(&check.stack.last);
// 	if (check.result == FAILURE || check.result == SUCCESS)
// 	{
// 		return (print_status("parser_save", "test_non_int",
// 		"Ensure exit and put Error if argv contains no int", FAILURE));
// 	}
// 	return (SUCCESS);
// }

// static int	test_bigger_int(void)
// {
// 	t_parser_save check;

// 	check.argv[0] = "./push_swap";
// 	check.argv[1] = "21474836479";
// 	check.argv[2] = "6  23";
// 	check.argv[3] = "1";
// 	check.argv[4] = "\0";
// 	check.stack.last = NULL;
// 	check.stack.size = 0;
// 	check.result = parser_save(check.argv, &check.stack);
// 	ft_lstclear(&check.stack.last);
// 	if (check.result == FAILURE || check.result == SUCCESS)
// 	{
// 		return (print_status("parser_save", "test_bigger_int",
// 		"Ensure exit and put Error if argv bigger than int", FAILURE));
// 	}
// 	return (SUCCESS);
// }

// static int	test_smaller_int(void)
// {
// 	t_parser_save check;

// 	check.argv[0] = "./push_swap";
// 	check.argv[1] = "-21474836481";
// 	check.argv[2] = "6  23";
// 	check.argv[3] = "1";
// 	check.argv[4] = "\0";
// 	check.stack.last = NULL;
// 	check.result = parser_save(check.argv, &check.stack);
// 	ft_lstclear(&check.stack.last);
// 	if (check.result == FAILURE || check.result == SUCCESS)
// 	{
// 		return (print_status("parser_save", "test_smaller_int",
// 		"Ensure exit and put Error if argv smaller than int", FAILURE));
// 	}
// 	return (SUCCESS);
// }

// static int	test_duplicates(void)
// {
// 	t_parser_save check;

// 	check.argv[0] = "./push_swap";
// 	check.argv[1] = "-9";
// 	check.argv[2] = "6  -9";
// 	check.argv[3] = "1";
// 	check.argv[4] = "\0";
// 	check.stack.last = NULL;
// 	check.result = parser_save(check.argv, &check.stack);
// 	ft_lstclear(&check.stack.last);
// 	if (check.result == FAILURE || check.result == SUCCESS)
// 	{
// 		return (print_status("parser_save", "test_duplicates",
// 		"Ensure exit and put Error if argv are duplicates", FAILURE));
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
	if (test_multiple_number_with_space())
		return (FAILURE);
	// if (test_sorted_number())
	// 	return (FAILURE);
	// if (test_no_int())
	// 	return (FAILURE);
	// if (test_bigger_int())
	// 	return (FAILURE);
	// if (test_smaller_int())
	// 	return (FAILURE);
	// if (test_duplicates())
	// 	return (FAILURE);
	return (SUCCESS);
}
