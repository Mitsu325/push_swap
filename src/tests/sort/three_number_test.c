/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_number_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:20:33 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/26 12:21:44 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_sort_three_number_sa_ra(void)
{
	t_stack	stack;

	stack.full_size = 3;
	stack.last_a = NULL;
	ft_lstadd_back(&stack.last_a, -1);
	ft_lstadd_back(&stack.last_a, 10);
	ft_lstadd_back(&stack.last_a, 3);
	sort(&stack);
	ft_putlst_fd(stack.last_a, 1);
	if (stack.last_a->next->data == -1 && stack.last_a->next->next->data == 3 &&
		stack.last_a->data == 10)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("three_number_test.c",
		"test_sort_three_number_sa_ra", "OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("three_number_test.c", "test_sort_three_number_sa_ra",
	"Ensure sort three numbers and put sa and ra operation", FAILURE));
}

static int	test_sort_three_number_sa(void)
{
	t_stack	stack;

	stack.full_size = 3;
	stack.last_a = NULL;
	ft_lstadd_back(&stack.last_a, 3);
	ft_lstadd_back(&stack.last_a, -1);
	ft_lstadd_back(&stack.last_a, 10);
	sort(&stack);
	ft_putlst_fd(stack.last_a, 1);
	if (stack.last_a->next->data == -1 && stack.last_a->next->next->data == 3 &&
		stack.last_a->data == 10)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("three_number_test.c",
		"test_sort_three_number_sa", "OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("three_number_test.c", "test_sort_three_number_sa",
	"Ensure sort three numbers and put sa operation", FAILURE));
}

static int	test_sort_three_number_rra(void)
{
	t_stack	stack;

	stack.full_size = 3;
	stack.last_a = NULL;
	ft_lstadd_back(&stack.last_a, 3);
	ft_lstadd_back(&stack.last_a, 10);
	ft_lstadd_back(&stack.last_a, -1);
	sort(&stack);
	ft_putlst_fd(stack.last_a, 1);
	if (stack.last_a->next->data == -1 && stack.last_a->next->next->data == 3 &&
		stack.last_a->data == 10)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("three_number_test.c",
		"test_sort_three_number_rra", "OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("three_number_test.c", "test_sort_three_number_rra",
	"Ensure sort three numbers and put rra operation", FAILURE));
}

static int	test_sort_three_number_ra(void)
{
	t_stack	stack;

	stack.full_size = 3;
	stack.last_a = NULL;
	ft_lstadd_back(&stack.last_a, 10);
	ft_lstadd_back(&stack.last_a, -1);
	ft_lstadd_back(&stack.last_a, 3);
	sort(&stack);
	ft_putlst_fd(stack.last_a, 1);
	if (stack.last_a->next->data == -1 && stack.last_a->next->next->data == 3 &&
		stack.last_a->data == 10)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("three_number_test.c",
		"test_sort_three_number_ra", "OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("three_number_test.c", "test_sort_three_number_ra",
	"Ensure sort three numbers and put ra operation", FAILURE));
}

static int	test_sort_three_number_sa_rra(void)
{
	t_stack	stack;

	stack.full_size = 3;
	stack.last_a = NULL;
	ft_lstadd_back(&stack.last_a, 10);
	ft_lstadd_back(&stack.last_a, 3);
	ft_lstadd_back(&stack.last_a, -1);
	sort(&stack);
	ft_putlst_fd(stack.last_a, 1);
	if (stack.last_a->next->data == -1 && stack.last_a->next->next->data == 3 &&
		stack.last_a->data == 10)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("three_number_test.c",
		"test_sort_three_number_sa_rra", "OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("three_number_test.c", "test_sort_three_number_sa_rra",
	"Ensure sort three numbers and put sa and rra operation", FAILURE));
}

int	three_number_test(void)
{
	if (test_sort_three_number_sa_ra())
		return (FAILURE);
	if (test_sort_three_number_sa())
		return (FAILURE);
	if (test_sort_three_number_rra())
		return (FAILURE);
	if (test_sort_three_number_ra())
		return (FAILURE);
	if (test_sort_three_number_sa_rra())
		return (FAILURE);
	return (SUCCESS);
}
