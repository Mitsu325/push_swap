/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:20:33 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/29 07:29:56 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	set_twenty_numbers(t_stack *stack)
{
	stack->full_size = 20;
	stack->size_a = stack->full_size;
	stack->last_a = NULL;
	stack->last_b = NULL;
	ft_lstadd_back(&stack->last_a, 8);
	ft_lstadd_back(&stack->last_a, -27);
	ft_lstadd_back(&stack->last_a, -20);
	ft_lstadd_back(&stack->last_a, 0);
	ft_lstadd_back(&stack->last_a, 24);
	ft_lstadd_back(&stack->last_a, 20);
	ft_lstadd_back(&stack->last_a, -8);
	ft_lstadd_back(&stack->last_a, 27);
	ft_lstadd_back(&stack->last_a, -701);
	ft_lstadd_back(&stack->last_a, 7);
	ft_lstadd_back(&stack->last_a, -1);
	ft_lstadd_back(&stack->last_a, -7);
	ft_lstadd_back(&stack->last_a, 5);
	ft_lstadd_back(&stack->last_a, -24);
	ft_lstadd_back(&stack->last_a, 2);
	ft_lstadd_back(&stack->last_a, -5);
	ft_lstadd_back(&stack->last_a, 202);
	ft_lstadd_back(&stack->last_a, -202);
	ft_lstadd_back(&stack->last_a, 701);
	ft_lstadd_back(&stack->last_a, -2);
}

static int	check_sorted_array(int *num, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (num[i] > num[i + 1])
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

// static void	put_arr(int *num, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("[%d]\n", num[i]);
// 		i++;
// 	}
// }

// static int	count_nodes(t_list *last)
// {
// 	t_list	*temp;
// 	int		count;

// 	count = 0;
// 	if (last == NULL)
// 		return (count);
// 	temp = last->next;
// 	while (temp != last)
// 	{
// 		count++;
// 		temp = temp->next;
// 	}
// 	count++;
// 	return (count);
// }

static int	test_num_format_array(void)
{
	t_stack	stack;
	int		*result;

	set_twenty_numbers(&stack);
	result = save_numbers_in_array(&stack);
	if (result[19] == -2)
	{
		free(result);
		ft_lstclear(&stack.last_a);
		return (print_status("sort_long_test.c", "test_num_format_array",
		"OK", SUCCESS));
	}
	free(result);
	ft_lstclear(&stack.last_a);
	return (print_status("sort_long_test.c", "test_num_format_array",
	"Ensure numbers save in array", FAILURE));
}

static int	test_sort_array(void)
{
	t_stack	stack;
	int		*result;

	set_twenty_numbers(&stack);
	result = save_numbers_in_array(&stack);
	quicksort(result, 0, stack.full_size - 1);
	// put_arr(result, stack.full_size);
	if (check_sorted_array(result, stack.full_size) == SUCCESS)
	{
		free(result);
		ft_lstclear(&stack.last_a);
		return (print_status("sort_long_test.c", "test_sort_array",
		"OK", SUCCESS));
	}
	free(result);
	ft_lstclear(&stack.last_a);
	return (print_status("sort_long_test.c", "test_sort_array",
	"Ensure sorted array", FAILURE));
}

static int	test_partition_a_and_push_b(void)
{
	t_stack	stack;

	set_twenty_numbers(&stack);
	partition_a_and_push_b(&stack);
	// printf("==============\n");
	// ft_putlst_fd(stack.last_a, 1);
	// printf("==============\n");
	// ft_putlst_fd(stack.last_b, 1);
	// printf("==============\n");
	if (stack.size_a == ((stack.full_size / 4) - 1))
	{
		ft_lstclear(&stack.last_a);
		ft_lstclear(&stack.last_b);
		return (print_status("sort_long_test.c", "test_partition_a_and_push_b",
		"OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	ft_lstclear(&stack.last_b);
	return (print_status("sort_long_test.c", "test_partition_a_and_push_b",
	"Ensure partition stack a and push smallest number to b", FAILURE));
}

static int	test_sort_number_remain_a(void)
{
	t_stack	stack;

	set_twenty_numbers(&stack);
	partition_a_and_push_b(&stack);
	sort_number_remain_a(&stack);
	printf("==============\n");
	ft_putlst_fd(stack.last_a, 1);
	printf("==============\n");
	ft_putlst_fd(stack.last_b, 1);
	printf("==============\n");
	if (check_sort(stack.last_a) == SUCCESS)
	{
		ft_lstclear(&stack.last_a);
		ft_lstclear(&stack.last_b);
		return (print_status("sort_long_test.c", "test_sort_number_remain_a",
		"OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	ft_lstclear(&stack.last_b);
	return (print_status("sort_long_test.c", "test_sort_number_remain_a",
	"Ensure sort of the remaining numbers in the stack a", FAILURE));
}

int	sort_long_test(void)
{
	if (test_num_format_array())
		return (FAILURE);
	if (test_sort_array())
		return (FAILURE);
	if (test_partition_a_and_push_b())
		return (FAILURE);
	if (test_sort_number_remain_a())
		return (FAILURE);
	return (SUCCESS);
}
