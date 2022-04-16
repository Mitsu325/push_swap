/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:56:16 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/16 17:36:29 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_check_sort
{
	t_list	*last;
	int		result;
}		t_check_sort;

static int	check_sort_null(void)
{
	t_check_sort	check;

	check.last = NULL;
	check.result = check_sort(check.last);
	if (check.result == FAILURE)
	{
		return (print_status("check_sort_test.c", "check_sort_null", "OK",
		SUCCESS));
	}
	return (print_status("check_sort_test.c", "check_sort_null",
	"Ensure returns 1 if it last is NULL", FAILURE));
}

static int	check_sort_one_number(void)
{
	t_check_sort	check;

	check.last = NULL;
	ft_lstadd_back(&check.last, 3);
	check.result = check_sort(check.last);
	ft_lstclear(&check.last);
	if (check.result == SUCCESS)
	{
		return (print_status("check_sort_test.c", "check_one_number", "OK",
		SUCCESS));
	}
	return (print_status("check_sort_test.c", "check_one_number",
	"Ensure returns 0 if it only has one number", FAILURE));
}

static int	check_sort_multiple_number(void)
{
	t_check_sort	check;

	check.last = NULL;
	ft_lstadd_back(&check.last, 3);
	ft_lstadd_back(&check.last, 5);
	ft_lstadd_back(&check.last, 97);
	ft_lstadd_back(&check.last, 123);
	check.result = check_sort(check.last);
	ft_lstclear(&check.last);
	if (check.result == SUCCESS)
	{
		return (print_status("check_sort_test.c", "check_sort_multiple_number",
		"OK", SUCCESS));
	}
	return (print_status("check_sort_test.c", "check_sort_multiple_number",
	"Ensure returns 0 if numbers are sorted", FAILURE));
}

static int	check_not_sort(void)
{
	t_check_sort	check;

	check.last = NULL;
	ft_lstadd_back(&check.last, 3);
	ft_lstadd_back(&check.last, 97);
	ft_lstadd_back(&check.last, 5);
	ft_lstadd_back(&check.last, 123);
	check.result = check_sort(check.last);
	ft_lstclear(&check.last);
	if (check.result == FAILURE)
	{
		return (print_status("check_sort_test.c", "check_not_sort",
		"OK", SUCCESS));
	}
	return (print_status("check_sort_test.c", "check_not_sort",
	"Ensure returns 1 if numbers are not sorted", FAILURE));
}

int	check_sort_test(void)
{
	if (check_sort_null())
		return (FAILURE);
	if (check_sort_one_number())
		return (FAILURE);
	if (check_sort_multiple_number())
		return (FAILURE);
	if (check_not_sort())
		return (FAILURE);
	return (SUCCESS);
}
