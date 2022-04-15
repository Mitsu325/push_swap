/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:10 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 07:37:54 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_is_int
{
	long int	num;
	int				result;
}		t_is_int;

int	check_is_integer(void)
{
	t_is_int check;

	check.num = 120;
	check.result = is_integer(check.num);
	if (check.result == SUCCESS)
	{
		return (print_status("is_integer_test.c", "check_is_integer", "OK",
		SUCCESS));
	}
	return (print_status("is_integer_test.c", "check_is_integer",
	"Ensure returns 0 if number is integer", FAILURE));
}

int	check_max_integer(void)
{
	t_is_int check;

	check.num = 2147483648;
	check.result = is_integer(check.num);
	if (check.result == FAILURE)
	{
		return (print_status("is_integer_test.c", "check_max_integer", "OK",
		SUCCESS));
	}
	return (print_status("is_integer_test.c", "check_max_integer",
	"Ensure returns 1 if number is greater than max integer", FAILURE));
}

int	check_min_integer(void)
{
	t_is_int check;

	check.num = -2147483650;
	check.result = is_integer(check.num);
	if (check.result == FAILURE)
	{
		return (print_status("is_integer_test.c", "check_min_integer", "OK",
		SUCCESS));
	}
	return (print_status("is_integer_test.c", "check_min_integer",
	"Ensure returns 1 if number is less than min integer", FAILURE));
}
