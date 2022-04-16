/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_test.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:10 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 07:37:54 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_check_list_int
{
	char	*list[3];
	int		result;
}		t_check_list_int;

static int	check_isdigit(void)
{
	t_check_list_int	check;

	check.list[0] = "0";
	check.list[1] = "2";
	check.list[2] = "\0";
	check.result = check_number(check.list);
	if (check.result == SUCCESS)
	{
		return (print_status("check_number_test.c", "check_isdigit", "OK",
		SUCCESS));
	}
	return (print_status("check_number_test.c", "check_isdigit",
	"Ensure returns 0 if list is integer", FAILURE));
}

static int	check_is_not_digit(void)
{
	t_check_list_int	check;

	check.list[0] = "0";
	check.list[1] = "A";
	check.list[2] = "\0";
	check.result = check_number(check.list);
	if (check.result == FAILURE)
	{
		return (print_status("check_number_test.c", "check_is_not_digit",
		"OK", SUCCESS));
	}
	return (print_status("check_number_test.c", "check_is_not_digit",
	"Ensure returns 1 if list containst other non-digit char", FAILURE));
}

static int	check_isnumber(void)
{
	t_check_list_int	check;

	check.list[0] = "10";
	check.list[1] = "202";
	check.list[2] = "\0";
	check.result = check_number(check.list);
	if (check.result == SUCCESS)
	{
		return (print_status("check_number_test.c", "check_isnumber",
		"OK", SUCCESS));
	}
	return (print_status("check_number_test.c", "check_isnumber",
	"Ensure returns 0 if is number", FAILURE));
}

static int	check_is_not_number(void)
{
	t_check_list_int	check;

	check.list[0] = "10";
	check.list[1] = "Hey";
	check.list[2] = "\0";
	check.result = check_number(check.list);
	if (check.result == FAILURE)
	{
		return (print_status("check_number_test.c", "check_is_not_number",
		"OK", SUCCESS));
	}
	return (print_status("check_number_test.c", "check_is_not_number",
	"Ensure returns 1 if if list containst other non-number char",
	FAILURE));
}

static int	check_num_with_space(void)
{
	t_check_list_int	check;

	check.list[0] = "012  1";
	check.list[1] = "2  70 80";
	check.list[2] = "\0";
	check.result = check_number(check.list);
	if (check.result == SUCCESS)
	{
		return (print_status("check_number_test.c",
		"check_num_with_space", "OK", SUCCESS));
	}
	return (print_status("check_number_test.c", "check_num_with_space",
	"Ensure returns 0 if number in format string with spaces", FAILURE));
}

static int	check_not_num_with_space(void)
{
	t_check_list_int	check;

	check.list[0] = "012	  1";
	check.list[1] = "2P  70";
	check.list[2] = "\0";
	check.result = check_number(check.list);
	if (check.result == FAILURE)
	{
		return (print_status("check_number_test.c",
		"check_not_num_with_space", "OK", SUCCESS));
	}
	return (print_status("check_number_test.c",
	"check_not_num_with_space",
	"Ensure returns 1 if list containst other non-number char", FAILURE));
}

static int	check_num_with_positive_sign(void)
{
	t_check_list_int	check;

	check.list[0] = "012  1";
	check.list[1] = "2  +70";
	check.list[2] = "\0";
	check.result = check_number(check.list);
	if (check.result == SUCCESS)
	{
		return (print_status("check_number_test.c",
		"check_num_with_positive_sign", "OK", SUCCESS));
	}
	return (print_status("check_number_test.c",
	"check_num_with_positive_sign",
	"Ensure returns 0 if list containst number with positive sign",
	FAILURE));
}

static int	check_num_with_negative_sign(void)
{
	t_check_list_int	check;

	check.list[0] = "-12  1";
	check.list[1] = "2  70";
	check.list[2] = "\0";
	check.result = check_number(check.list);
	if (check.result == SUCCESS)
	{
		return (print_status("check_number_test.c",
		"check_num_with_negative_sign", "OK", SUCCESS));
	}
	return (print_status("check_number_test.c",
	"check_num_with_negative_sign",
	"Ensure returns 0 if list containst number with negative sign",
	FAILURE));
}

int	check_list_int(void)
{
	if (check_isdigit())
		return (FAILURE);
	if (check_is_not_digit())
		return (FAILURE);
	if (check_isnumber())
		return (FAILURE);
	if (check_is_not_number())
		return (FAILURE);
	if (check_num_with_space())
		return (FAILURE);
	if (check_not_num_with_space())
		return (FAILURE);
	if (check_num_with_positive_sign())
		return (FAILURE);
	if (check_num_with_negative_sign())
		return (FAILURE);
	return (SUCCESS);
}
