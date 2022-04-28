/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:20:33 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/28 06:10:46 by pmitsuko         ###   ########.fr       */
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

static void	put_arr(int *num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("[%d]\n", num[i]);
		i++;
	}
}

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
	put_arr(result, stack.full_size);
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

int	sort_long_test(void)
{
	if (test_num_format_array())
		return (FAILURE);
	if (test_sort_array())
		return (FAILURE);
	return (SUCCESS);
}
