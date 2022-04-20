/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 06:12:57 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/20 06:13:04 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_check_rotate
{
	t_list	*last;
}		t_check_rotate;

static int	check_no_elements(void)
{
	t_check_rotate	check;

	check.last = NULL;
	rotate(&check.last);
	if (check.last == NULL)
	{
		return (print_status("rotate_test.c", "check_no_elements", "OK",
		SUCCESS));
	}
	return (print_status("rotate_test.c", "check_no_elements",
	"Ensure do nothing if there is no elements", FAILURE));
}

static int	check_one_element(void)
{
	t_check_rotate	check;

	check.last = NULL;
	ft_lstadd_back(&check.last, 3);
	rotate(&check.last);
	if (check.last->next->data == 3)
	{
		ft_lstclear(&check.last);
		return (print_status("rotate_test.c", "check_one_element", "OK",
		SUCCESS));
	}
	ft_lstclear(&check.last);
	return (print_status("rotate_test.c", "check_one_element",
	"Ensure do nothing if there is only one element", FAILURE));
}

static int	check_rotate(void)
{
	t_check_rotate	check;

	check.last = NULL;
	ft_lstadd_back(&check.last, 3);
	ft_lstadd_back(&check.last, 1);
	ft_lstadd_back(&check.last, 12);
	ft_lstadd_back(&check.last, 17);
	rotate(&check.last);
	ft_putlst_fd(check.last, 1);
	if (check.last->next->data == 1 && check.last->data == 3)
	{
		ft_lstclear(&check.last);
		return (print_status("rotate_test.c", "check_rotate", "OK", SUCCESS));
	}
	ft_lstclear(&check.last);
	return (print_status("rotate_test.c", "check_rotate",
	"Ensure the first element becomes the last one", FAILURE));
}

int	rotate_test(void)
{
	if (check_no_elements())
		return (FAILURE);
	if (check_one_element())
		return (FAILURE);
	if (check_rotate())
		return (FAILURE);
	return (SUCCESS);
}
