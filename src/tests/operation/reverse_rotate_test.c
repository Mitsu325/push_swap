/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:24:40 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/20 06:21:18 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_check_rev_rotate
{
	t_list	*last;
}		t_check_rev_rotate;

static int	check_no_elements(void)
{
	t_check_rev_rotate	check;

	check.last = NULL;
	reverse_rotate(&check.last);
	if (check.last == NULL)
	{
		return (print_status("reverse_rotate_test.c", "check_no_elements", "OK",
		SUCCESS));
	}
	return (print_status("reverse_rotate_test.c", "check_no_elements",
	"Ensure do nothing if there is no elements", FAILURE));
}

static int	check_one_element(void)
{
	t_check_rev_rotate	check;

	check.last = NULL;
	ft_lstadd_back(&check.last, 3);
	reverse_rotate(&check.last);
	if (check.last->next->data == 3)
	{
		ft_lstclear(&check.last);
		return (print_status("reverse_rotate_test.c", "check_one_element", "OK",
		SUCCESS));
	}
	ft_lstclear(&check.last);
	return (print_status("reverse_rotate_test.c", "check_one_element",
	"Ensure do nothing if there is only one element", FAILURE));
}

static int	check_reverse_rotate(void)
{
	t_check_rev_rotate	check;

	check.last = NULL;
	ft_lstadd_back(&check.last, 3);
	ft_lstadd_back(&check.last, 1);
	ft_lstadd_back(&check.last, 12);
	ft_lstadd_back(&check.last, 17);
	reverse_rotate(&check.last);
	ft_putlst_fd(check.last, 1);
	if (check.last->next->data == 17 && check.last->data == 12)
	{
		ft_lstclear(&check.last);
		return (print_status("reverse_rotate_test.c", "check_reverse_rotate",
		"OK", SUCCESS));
	}
	ft_lstclear(&check.last);
	return (print_status("reverse_rotate_test.c", "check_reverse_rotate",
	"Ensure the last element becomes the first one", FAILURE));
}

int	reverse_rotate_test(void)
{
	if (check_no_elements())
		return (FAILURE);
	if (check_one_element())
		return (FAILURE);
	if (check_reverse_rotate())
		return (FAILURE);
	return (SUCCESS);
}
