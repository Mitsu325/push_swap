/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:24:40 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/21 15:23:00 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_check_swap
{
	t_list	*last;
}		t_check_swap;

static int	check_no_elements(void)
{
	t_check_swap	check;

	check.last = NULL;
	swap(&check.last);
	if (check.last == NULL)
	{
		return (print_status("swap_test.c", "check_no_elements", "OK",
		SUCCESS));
	}
	return (print_status("swap_test.c", "check_no_elements",
	"Ensure do nothing if there is no elements", FAILURE));
}

static int	check_one_element(void)
{
	t_check_swap	check;

	check.last = NULL;
	ft_lstadd_back(&check.last, 3);
	swap(&check.last);
	if (check.last->next->data == 3)
	{
		ft_lstclear(&check.last);
		return (print_status("swap_test.c", "check_one_element", "OK",
		SUCCESS));
	}
	ft_lstclear(&check.last);
	return (print_status("swap_test.c", "check_one_element",
	"Ensure do nothing if there is only one element", FAILURE));
}

static int	check_swap_top(void)
{
	t_check_swap	check;

	check.last = NULL;
	ft_lstadd_back(&check.last, 3);
	ft_lstadd_back(&check.last, 1);
	ft_lstadd_back(&check.last, 12);
	ft_lstadd_back(&check.last, 17);
	swap(&check.last);
	ft_putlst_fd(check.last, 1);
	if (check.last->next->data == 1)
	{
		ft_lstclear(&check.last);
		return (print_status("swap_test.c", "check_swap_top", "OK", SUCCESS));
	}
	ft_lstclear(&check.last);
	return (print_status("swap_test.c", "check_swap_top",
	"Ensure swap the first two elements at the top of stack", FAILURE));
}

static int	check_swap_two_numbers(void)
{
	t_check_swap	check;

	check.last = NULL;
	ft_lstadd_back(&check.last, 3);
	ft_lstadd_back(&check.last, 1);
	swap(&check.last);
	ft_putlst_fd(check.last, 1);
	if (check.last->next->data == 1)
	{
		ft_lstclear(&check.last);
		return (print_status("swap_test.c", "check_swap_two_numbers", "OK",
		SUCCESS));
	}
	ft_lstclear(&check.last);
	return (print_status("swap_test.c", "check_swap_two_numbers",
	"Ensure swap the two elements in the stack", FAILURE));
}

int	swap_test(void)
{
	if (check_no_elements())
		return (FAILURE);
	if (check_one_element())
		return (FAILURE);
	if (check_swap_top())
		return (FAILURE);
	if (check_swap_two_numbers())
		return (FAILURE);
	return (SUCCESS);
}
