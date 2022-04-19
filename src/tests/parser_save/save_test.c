/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:10 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/19 07:19:08 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_check_save
{
	char	*number;
	t_stack	stack;
	int		result;
}		t_check_save;

static int	check_save_number(void)
{
	t_check_save	check;

	check.number = "0";
	check.stack.last = NULL;
	check.result = save_number(&check.stack, check.number);
	ft_lstclear(&check.stack.last);
	if (check.result == SUCCESS)
	{
		return (print_status("save_test.c", "check_save_number", "OK",
		SUCCESS));
	}
	return (print_status("save_test.c", "check_save_number",
	"Ensure returns 0 if save number in circular linked list", FAILURE));
}

// * The number after the tab is disregarded but not return an error
static int	check_save_number_with_space(void)
{
	t_check_save	check;

	check.number = "0  4        34	123";
	check.stack.last = NULL;
	check.result = save_number(&check.stack, check.number);
	ft_lstclear(&check.stack.last);
	if (check.result == SUCCESS)
	{
		return (print_status("save_test.c", "check_save_number_with_space",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_number_with_space",
	"Ensure returns 0 if save consecutive number separated space in circular linked list",
	FAILURE));
}

static int	check_save_max_int(void)
{
	t_check_save	check;

	check.number = "2147483647";
	check.stack.last = NULL;
	check.result = save_number(&check.stack, check.number);
	ft_putlst_fd(check.stack.last, 1);
	ft_lstclear(&check.stack.last);
	if (check.result == SUCCESS)
	{
		return (print_status("save_test.c", "check_save_max_int",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_max_int",
	"Ensure returns 0 if save max int in circular linked list",
	FAILURE));
}

static int	check_save_min_int(void)
{
	t_check_save	check;

	check.number = "-2147483648";
	check.stack.last = NULL;
	check.result = save_number(&check.stack, check.number);
	ft_putlst_fd(check.stack.last, 1);
	ft_lstclear(&check.stack.last);
	if (check.result == SUCCESS)
	{
		return (print_status("save_test.c", "check_save_min_int",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_min_int",
	"Ensure returns 0 if save min int in circular linked list",
	FAILURE));
}

static int	check_save_greater_max_int(void)
{
	t_check_save	check;

	check.number = "+2147483650";
	check.stack.last = NULL;
	check.result = save_number(&check.stack, check.number);
	if (check.result == FAILURE)
	{
		return (print_status("save_test.c", "check_save_greater_max_int",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_greater_max_int",
	"Ensure returns 1 if number is greater than max int",
	FAILURE));
}

static int	check_save_less_min_int(void)
{
	t_check_save	check;

	check.number = "-2147483650";
	check.stack.last = NULL;
	check.result = save_number(&check.stack, check.number);
	if (check.result == FAILURE)
	{
		return (print_status("save_test.c", "check_save_less_min_int",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_less_min_int",
	"Ensure returns 1 if number is less than min int",
	FAILURE));
}

static int	check_save_duplicate(void)
{
	t_check_save	check;

	check.number = "3";
	check.stack.last = NULL;
	check.result = save_number(&check.stack, check.number);
	check.number = "9";
	check.result = save_number(&check.stack, check.number);
	check.number = "5";
	check.result = save_number(&check.stack, check.number);
	check.number = "9";
	check.result = save_number(&check.stack, check.number);
	ft_lstclear(&check.stack.last);
	if (check.result == FAILURE)
	{
		return (print_status("save_test.c", "check_save_duplicate",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_duplicate",
	"Ensure returns 1 if number is duplicate",
	FAILURE));
}

static int	check_save_consecutive_sign_first(void)
{
	t_check_save	check;

	check.number = "----325";
	check.stack.last = NULL;
	check.result = save_number(&check.stack, check.number);
	ft_lstclear(&check.stack.last);
	if (check.result == FAILURE)
	{
		return (print_status("save_test.c", "check_save_consecutive_sign_first",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_consecutive_sign_first",
	"Ensure returns 1 if number is consecutive at the beginning",
	FAILURE));
}

static int	check_save_consecutive_sign_middle(void)
{
	t_check_save	check;

	check.number = "32-+5";
	check.stack.last = NULL;
	check.result = save_number(&check.stack, check.number);
	ft_lstclear(&check.stack.last);
	if (check.result == FAILURE)
	{
		return (print_status("save_test.c", "check_save_consecutive_sign_middle",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_consecutive_sign_middle",
	"Ensure returns 1 if number is consecutive in the middle",
	FAILURE));
}

static int	check_save_consecutive_sign_last(void)
{
	t_check_save	check;

	check.number = "325--";
	check.stack.last = NULL;
	check.result = save_number(&check.stack, check.number);
	ft_lstclear(&check.stack.last);
	if (check.result == FAILURE)
	{
		return (print_status("save_test.c", "check_save_consecutive_sign_last",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_consecutive_sign_last",
	"Ensure returns 1 if number is consecutive at the end",
	FAILURE));
}

int	check_save(void)
{
	if (check_save_number())
		return (FAILURE);
	if (check_save_number_with_space())
		return (FAILURE);
	if (check_save_max_int())
		return (FAILURE);
	if (check_save_min_int())
		return (FAILURE);
	if (check_save_greater_max_int())
		return (FAILURE);
	if (check_save_less_min_int())
		return (FAILURE);
	if (check_save_duplicate())
		return (FAILURE);
	if (check_save_consecutive_sign_first())
		return (FAILURE);
	if (check_save_consecutive_sign_middle())
		return (FAILURE);
	if (check_save_consecutive_sign_last())
		return (FAILURE);
	return (SUCCESS);
}
