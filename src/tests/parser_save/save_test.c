/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:10 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/15 07:37:54 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_check_save
{
	char	*number;
	t_list	*last;
	int		result;
}		t_check_save;

int	check_save_number(void)
{
	t_check_save	check;

	check.number = "0";
	check.last = NULL;
	check.result = save(&check.last, check.number);
	ft_lstclear(&check.last);
	if (check.result == SUCCESS)
	{
		return (print_status("save_test.c", "check_save_number", "OK",
		SUCCESS));
	}
	return (print_status("save_test.c", "check_save_number",
	"Ensure returns 0 if save number in circular linked list", FAILURE));
}

// * The number after the tab is disregarded but not return an error
int	check_save_number_with_space(void)
{
	t_check_save	check;

	check.number = "0  4        34	123";
	check.last = NULL;
	check.result = save(&check.last, check.number);
	ft_lstclear(&check.last);
	if (check.result == SUCCESS)
	{
		return (print_status("save_test.c", "check_save_number_with_space",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_number_with_space",
	"Ensure returns 0 if save consecutive number separated space in circular linked list",
	FAILURE));
}

int	check_save_max_int(void)
{
	t_check_save	check;

	check.number = "2147483647";
	check.last = NULL;
	check.result = save(&check.last, check.number);
	ft_putlst_fd(check.last, 1);
	ft_lstclear(&check.last);
	if (check.result == SUCCESS)
	{
		return (print_status("save_test.c", "check_save_max_int",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_max_int",
	"Ensure returns 0 if save max int in circular linked list",
	FAILURE));
}

int	check_save_min_int(void)
{
	t_check_save	check;

	check.number = "-2147483648";
	check.last = NULL;
	check.result = save(&check.last, check.number);
	ft_putlst_fd(check.last, 1);
	ft_lstclear(&check.last);
	if (check.result == SUCCESS)
	{
		return (print_status("save_test.c", "check_save_min_int",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_min_int",
	"Ensure returns 0 if save min int in circular linked list",
	FAILURE));
}

int	check_save_greater_max_int(void)
{
	t_check_save	check;

	check.number = "+2147483650";
	check.last = NULL;
	check.result = save(&check.last, check.number);
	if (check.result == FAILURE)
	{
		return (print_status("save_test.c", "check_save_greater_max_int",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_greater_max_int",
	"Ensure returns 1 if number is greater than max int",
	FAILURE));
}

int	check_save_less_min_int(void)
{
	t_check_save	check;

	check.number = "-2147483650";
	check.last = NULL;
	check.result = save(&check.last, check.number);
	if (check.result == FAILURE)
	{
		return (print_status("save_test.c", "check_save_less_min_int",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_less_min_int",
	"Ensure returns 1 if number is less than min int",
	FAILURE));
}

int	check_save_duplicate(void)
{
	t_check_save	check;

	check.number = "3";
	check.last = NULL;
	check.result = save(&check.last, check.number);
	check.number = "9";
	check.result = save(&check.last, check.number);
	check.number = "5";
	check.result = save(&check.last, check.number);
	check.number = "9";
	check.result = save(&check.last, check.number);
	ft_lstclear(&check.last);
	if (check.result == FAILURE)
	{
		return (print_status("save_test.c", "check_save_duplicate",
		"OK", SUCCESS));
	}
	return (print_status("save_test.c", "check_save_duplicate",
	"Ensure returns 1 if number is duplicate",
	FAILURE));
}
