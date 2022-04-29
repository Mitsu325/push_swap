/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_one_hundred_numbers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:13:21 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/29 04:58:22 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void swap_ptr(int *ptr_a, int *ptr_b)
{
	int	temp;

	temp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = temp;
}

static int	partition(int *num, int low_index, int high_index)
{
	int	pivot;
	int	i;
	int	j;

	pivot = num[high_index];
	i = low_index - 1;
	j = low_index;
	while (j <= high_index - 1)
	{
		if (*(num + j) < pivot)
		{
			i++;
			swap_ptr(&num[i], &num[j]);
		}
		j++;
	}
	swap_ptr(&num[i + 1], &num[high_index]);
	return (i + 1);
}

void	quicksort(int *num, int low_index, int high_index)
{
	int	pivot;

	if (low_index < high_index)
	{
		pivot = partition(num, low_index, high_index);
		quicksort(num, low_index, pivot - 1);
		quicksort(num, pivot + 1, high_index);
	}
}

int	*save_numbers_in_array(t_stack *stack)
{
	t_list	*temp;
	int		*num;
	int		i;

	num = malloc(sizeof(int) * stack->full_size);
	if (num == NULL)
		return (NULL);
	temp = stack->last_a->next;
	i = 0;
	while (temp != stack->last_a)
	{
		num[i++] = temp->data;
		temp = temp->next;
	}
	num[i] = temp->data;
	return (num);
}

static int	get_partition(int size)
{
	if (size < 100)
		return (4);
	return (8);
}

static int	get_pivot(int *sorted_number, int size, int factor, int divisor)
{
	int	pivot;

	pivot = sorted_number[((size * factor) / divisor)];
	return (pivot);
}

int	index_of_small_pivot(t_list *last, int pivot)
{
	t_list	*temp;
	int		i;

	i = -1;
	temp = last->next;
	while (temp != last)
	{
		i++;
		if (temp->data <= pivot)
			return (i);
		temp = temp->next;
	}
	if (temp->data <= pivot)
	{
		i++;
		return (i);
	}
	return (-1);
}

void	move_number_to_top(t_stack *stack, int index)
{
	int	half_size;

	if (index == 1)
	{
		sa(stack);
		return ;
	}
	half_size = (stack->size_a / 2) + (stack->size_a % 2);
	if (index < half_size)
	{
		while (index != 0)
		{
			ra(stack);
			index--;
		}
		return ;
	}
	while (index != stack->size_a)
	{
		rra(stack);
		index++;
	}
}

static void	push_small_number_pivot_to_b(t_stack *stack, int pivot)
{
	int		index;

	index = index_of_small_pivot(stack->last_a, pivot);
	while (index != -1)
	{
		if (index != 0)
			move_number_to_top(stack, index);
		pb(stack);
		stack->size_a--;
		index = index_of_small_pivot(stack->last_a, pivot);
	}
}

void	partition_a_and_push_b(t_stack *stack)
{
	int	*sorted_number;
	int	i;
	int	partition;
	int	pivot;

	i = 1;
	partition = get_partition(stack->size_a);
	sorted_number = save_numbers_in_array(stack);
	quicksort(sorted_number, 0, stack->full_size - 1);
	while (i < partition)
	{
		pivot = get_pivot(sorted_number, stack->full_size, i, partition);
		push_small_number_pivot_to_b(stack, pivot);
		i++;
	}
	free(sorted_number);
}

// int	sort_up_to_one_hundred_numbers(t_stack *stack)
// {
// 	return (SUCCESS);
// }
