/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_integer_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:10 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 19:00:00 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_check_list_int
{
	char	*list[3];
	int		result;
}		t_check_list_int;

int	check_isdigit(void)
{
	t_check_list_int	check;

	check.list[0] = "0";
	check.list[1] = "2";
	check.list[2] = "\0";
	check.result = check_list_integer(check.list);
	if (check.result == EXIT_SUCCESS)
	{
		return (print_status("check_list_integer_test.c", "check_isdigit", "OK",
		EXIT_SUCCESS));
	}
	return (print_status("check_list_integer_test.c", "check_isdigit",
	"Ensure returns 0 if list is integer", EXIT_FAILURE));
}

int	check_is_not_digit(void)
{
	t_check_list_int	check;

	check.list[0] = "0";
	check.list[1] = "A";
	check.list[2] = "\0";
	check.result = check_list_integer(check.list);
	if (check.result == EXIT_FAILURE)
	{
		return (print_status("check_list_integer_test.c", "check_is_not_digit",
		"OK", EXIT_SUCCESS));
	}
	return (print_status("check_list_integer_test.c", "check_is_not_digit",
	"Ensure returns 1 if list containst other non-digit char", EXIT_FAILURE));
}

int	check_isnumber(void)
{
	t_check_list_int	check;

	check.list[0] = "10";
	check.list[1] = "202";
	check.list[2] = "\0";
	check.result = check_list_integer(check.list);
	if (check.result == EXIT_SUCCESS)
	{
		return (print_status("check_list_integer_test.c", "check_isnumber",
		"OK", EXIT_SUCCESS));
	}
	return (print_status("check_list_integer_test.c", "check_isnumber",
	"Ensure returns 0 if is number", EXIT_FAILURE));
}

int	check_is_not_number(void)
{
	t_check_list_int	check;

	check.list[0] = "10";
	check.list[1] = "Hey";
	check.list[2] = "\0";
	check.result = check_list_integer(check.list);
	if (check.result == EXIT_FAILURE)
	{
		return (print_status("check_list_integer_test.c", "check_is_not_number",
		"OK", EXIT_SUCCESS));
	}
	return (print_status("check_list_integer_test.c", "check_is_not_number",
	"Ensure returns 1 if if list containst other non-number char",
	EXIT_FAILURE));
}

int	check_num_with_space(void)
{
	t_check_list_int	check;

	check.list[0] = "012  1";
	check.list[1] = "2  	70	80";
	check.list[2] = "\0";
	check.result = check_list_integer(check.list);
	if (check.result == EXIT_SUCCESS)
	{
		return (print_status("check_list_integer_test.c",
		"check_num_with_space", "OK", EXIT_SUCCESS));
	}
	return (print_status("check_list_integer_test.c", "check_num_with_space",
	"Ensure returns 0 if number in format string with spaces", EXIT_FAILURE));
}

int	check_not_num_with_space(void)
{
	t_check_list_int	check;

	check.list[0] = "012  1";
	check.list[1] = "2P  	70";
	check.list[2] = "\0";
	check.result = check_list_integer(check.list);
	if (check.result == EXIT_FAILURE)
	{
		return (print_status("check_list_integer_test.c",
		"check_not_num_with_space", "OK", EXIT_SUCCESS));
	}
	return (print_status("check_list_integer_test.c",
	"check_not_num_with_space",
	"Ensure returns 1 if list containst other non-number char", EXIT_FAILURE));
}
