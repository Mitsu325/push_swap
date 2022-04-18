/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:24:40 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/18 07:36:51 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

typedef struct s_check_swap
{
	t_list	*last_a;
	t_list	*last_b;
}		t_check_swap;

static int	check_empty_from_stack(void)
{
	t_check_swap	check;

	check.last_a = NULL;
	check.last_b = NULL;
	ft_lstadd_back(&check.last_a, 3);
	push(&check.last_a, &check.last_b);
	if (check.last_b == NULL)
	{
		ft_lstclear(&check.last_a);
		return (print_status("push_test.c", "check_empty_from_stack", "OK",
		SUCCESS));
	}
	ft_lstclear(&check.last_a);
	return (print_status("push_test.c", "check_empty_from_stack",
	"Ensure do nothing if the stack is empty", FAILURE));
}

static int	check_rmv_first_node_from_stack(void)
{
	t_check_swap	check;

	check.last_a = NULL;
	check.last_b = NULL;
	ft_lstadd_back(&check.last_a, 3);
	ft_lstadd_back(&check.last_b, 5);
	ft_lstadd_back(&check.last_b, 9);
	// ft_lstadd_back(&check.last_b, 14);
	push(&check.last_a, &check.last_b);
	// ft_putlst_fd(check.last_b, 1);
	if (check.last_b->next->data == 9)
	{
		ft_lstclear(&check.last_a);
		ft_lstclear(&check.last_b);
		return (print_status("push_test.c", "check_rmv_first_node_from_stack",
		"OK", SUCCESS));
	}
	ft_lstclear(&check.last_a);
	ft_lstclear(&check.last_b);
	return (print_status("push_test.c", "check_rmv_first_node_from_stack",
	"Ensure remove the first node from the stack", FAILURE));
}

static int	check_rmv_first_node_from_stack_null(void)
{
	t_check_swap	check;

	check.last_a = NULL;
	check.last_b = NULL;
	ft_lstadd_back(&check.last_a, 3);
	ft_lstadd_back(&check.last_b, 5);
	push(&check.last_a, &check.last_b);
	if (check.last_b == NULL)
	{
		ft_lstclear(&check.last_a);
		return (print_status("push_test.c", "check_rmv_first_node_from_stack_null",
		"OK", SUCCESS));
	}
	ft_lstclear(&check.last_a);
	return (print_status("push_test.c", "check_rmv_first_node_from_stack_null",
	"Ensure remove the first node from the stack and set NULL", FAILURE));
}

static int	check_insert_beginning_to_stack_null(void)
{
	t_check_swap	check;

	check.last_a = NULL;
	check.last_b = NULL;
	ft_lstadd_back(&check.last_b, 8);
	push(&check.last_a, &check.last_b);
	if (check.last_a->data == 8)
	{
		ft_lstclear(&check.last_a);
		return (print_status("push_test.c", "check_insert_beginning_to_stack_null",
		"OK", SUCCESS));
	}
	ft_lstclear(&check.last_a);
	return (print_status("push_test.c", "check_insert_beginning_to_stack_null",
	"Ensure insert the beginning to the null stack", FAILURE));
}

static int	check_insert_beginning_to_stack(void)
{
	t_check_swap	check;

	check.last_a = NULL;
	check.last_b = NULL;
	ft_lstadd_back(&check.last_a, 3);
	ft_lstadd_back(&check.last_a, 7);
	ft_lstadd_back(&check.last_b, 8);
	ft_lstadd_back(&check.last_b, 10);
	push(&check.last_a, &check.last_b);
	ft_putlst_fd(check.last_a, 1);
	ft_putstr_fd("=======\n", 1);
	ft_putlst_fd(check.last_b, 1);
	if (check.last_a->next->data == 8)
	{
		ft_lstclear(&check.last_a);
		ft_lstclear(&check.last_b);
		return (print_status("push_test.c", "check_insert_beginning_to_stack",
		"OK", SUCCESS));
	}
	ft_lstclear(&check.last_a);
	ft_lstclear(&check.last_b);
	return (print_status("push_test.c", "check_insert_beginning_to_stack",
	"Ensure insert the beginning to the stack", FAILURE));
}

int	push_test(void)
{
	if (check_empty_from_stack())
		return (FAILURE);
	if (check_rmv_first_node_from_stack())
		return (FAILURE);
	if (check_rmv_first_node_from_stack_null())
		return (FAILURE);
	if (check_insert_beginning_to_stack_null())
		return (FAILURE);
	if (check_insert_beginning_to_stack())
		return (FAILURE);
	return (SUCCESS);
}
