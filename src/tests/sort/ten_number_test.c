/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_number_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:20:33 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/27 05:05:50 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_sort_eight_numbers(void)
{
	t_stack	stack;

	stack.full_size = 8;
	stack.size_a = stack.full_size;
	stack.last_a = NULL;
	stack.last_b = NULL;
	ft_lstadd_back(&stack.last_a, 8);
	ft_lstadd_back(&stack.last_a, 1);
	ft_lstadd_back(&stack.last_a, 20);
	ft_lstadd_back(&stack.last_a, 7);
	ft_lstadd_back(&stack.last_a, -5);
	ft_lstadd_back(&stack.last_a, 2);
	ft_lstadd_back(&stack.last_a, 202);
	ft_lstadd_back(&stack.last_a, 701);
	sort(&stack);
	ft_putlst_fd(stack.last_a, 1);
	if (check_sort(stack.last_a) == SUCCESS)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("ten_number_test.c", "test_sort_eight_numbers",
		"OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("ten_number_test.c", "test_sort_eight_numbers",
	"Ensure sorted eight numbers", FAILURE));
}

static int	test_sort_ten_numbers(void)
{
	t_stack	stack;

	stack.full_size = 10;
	stack.size_a = stack.full_size;
	stack.last_a = NULL;
	stack.last_b = NULL;
	ft_lstadd_back(&stack.last_a, 8);
	ft_lstadd_back(&stack.last_a, 1);
	ft_lstadd_back(&stack.last_a, 24);
	ft_lstadd_back(&stack.last_a, 20);
	ft_lstadd_back(&stack.last_a, 27);
	ft_lstadd_back(&stack.last_a, 7);
	ft_lstadd_back(&stack.last_a, -5);
	ft_lstadd_back(&stack.last_a, 2);
	ft_lstadd_back(&stack.last_a, 202);
	ft_lstadd_back(&stack.last_a, 701);
	sort(&stack);
	ft_putlst_fd(stack.last_a, 1);
	if (check_sort(stack.last_a) == SUCCESS)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("ten_number_test.c", "test_sort_ten_numbers",
		"OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("ten_number_test.c", "test_sort_ten_numbers",
	"Ensure sorted ten numbers", FAILURE));
}

int	ten_number_test(void)
{
	if (test_sort_eight_numbers())
		return (FAILURE);
	if (test_sort_ten_numbers())
		return (FAILURE);
	return (SUCCESS);
}
