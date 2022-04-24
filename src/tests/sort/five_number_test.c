/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_number_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:20:33 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/24 18:38:53 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_find_smallest_num_node(void)
{
	t_stack	stack;
	int		smallest_num_index;

	stack.size = 5;
	stack.last_a = NULL;
	stack.last_b = NULL;
	ft_lstadd_back(&stack.last_a, 1);
	ft_lstadd_back(&stack.last_a, 20);
	ft_lstadd_back(&stack.last_a, 10);
	ft_lstadd_back(&stack.last_a, 2);
	ft_lstadd_back(&stack.last_a, -7);
	smallest_num_index = find_smallest_num_node(stack.last_a);
	if (smallest_num_index == 4)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("five_number_test.c", "test_find_smallest_num_node",
		"OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("five_number_test.c", "test_find_smallest_num_node",
	"Ensure returns position node with smallest number", FAILURE));
}

static int	test_push_b_lower_values(void)
{
	t_stack	stack;

	stack.size = 5;
	stack.last_a = NULL;
	stack.last_b = NULL;
	ft_lstadd_back(&stack.last_a, 8);
	ft_lstadd_back(&stack.last_a, 1);
	ft_lstadd_back(&stack.last_a, 20);
	ft_lstadd_back(&stack.last_a, 7);
	ft_lstadd_back(&stack.last_a, 2);
	push_smallest_number_to_b(&stack, 3);
	ft_putlst_fd(stack.last_b, 1);
	if (stack.last_b->next->data == 2 && stack.last_b->data == 1)
	{
		ft_lstclear(&stack.last_a);
		ft_lstclear(&stack.last_b);
		return (print_status("five_number_test.c", "test_push_b_lower_values",
		"OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	ft_lstclear(&stack.last_b);
	return (print_status("five_number_test.c", "test_push_b_lower_values",
	"Ensure push lower values to stack b", FAILURE));
}

static int	test_sort_four_numbers(void)
{
	t_stack	stack;

	stack.size = 4;
	stack.last_a = NULL;
	stack.last_b = NULL;
	ft_lstadd_back(&stack.last_a, 8);
	ft_lstadd_back(&stack.last_a, 1);
	ft_lstadd_back(&stack.last_a, 20);
	ft_lstadd_back(&stack.last_a, 7);
	sort(&stack);
	ft_putlst_fd(stack.last_a, 1);
	if (check_sort(stack.last_a) == SUCCESS)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("five_number_test.c", "test_sort_four_numbers",
		"OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("five_number_test.c", "test_sort_four_numbers",
	"Ensure sorted four numbers", FAILURE));
}

static int	test_sort_five_numbers(void)
{
	t_stack	stack;

	stack.size = 5;
	stack.last_a = NULL;
	stack.last_b = NULL;
	ft_lstadd_back(&stack.last_a, 8);
	ft_lstadd_back(&stack.last_a, 1);
	ft_lstadd_back(&stack.last_a, 20);
	ft_lstadd_back(&stack.last_a, 7);
	ft_lstadd_back(&stack.last_a, -3);
	sort(&stack);
	ft_putlst_fd(stack.last_a, 1);
	if (check_sort(stack.last_a) == SUCCESS)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("five_number_test.c", "test_sort_five_numbers",
		"OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("five_number_test.c", "test_sort_five_numbers",
	"Ensure sorted five numbers", FAILURE));
}

int	five_number_test(void)
{
	if (test_find_smallest_num_node())
		return (FAILURE);
	if (test_push_b_lower_values())
		return (FAILURE);
	if (test_sort_four_numbers())
		return (FAILURE);
	if (test_sort_five_numbers())
		return (FAILURE);
	return (SUCCESS);
}
