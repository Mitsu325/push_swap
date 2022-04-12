/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:24:10 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/12 05:51:22 by pmitsuko         ###   ########.fr       */
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
	if (check.result == EXIT_SUCCESS)
	{
		return (print_status("parser_test.c", "check_save_number", "OK",
		EXIT_SUCCESS));
	}
	return (print_status("parser_test.c", "check_save_number",
	"Ensure returns 0 if save number in circular linked list", EXIT_FAILURE));
}

// * The number after the tab is disregarded but not return an error
int	check_save_number_with_space(void)
{
	t_check_save	check;

	check.number = "0  4        34	123";
	check.last = NULL;
	check.result = save(&check.last, check.number);
	ft_lstclear(&check.last);
	if (check.result == EXIT_SUCCESS)
	{
		return (print_status("parser_test.c", "check_save_number_with_space",
		"OK", EXIT_SUCCESS));
	}
	return (print_status("parser_test.c", "check_save_number_with_space",
	"Ensure returns 0 if save consecutive number separated space in circular linked list",
	EXIT_FAILURE));
}
