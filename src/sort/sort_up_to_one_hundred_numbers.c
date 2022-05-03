/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_one_hundred_numbers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:13:21 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/03 04:46:03 by pmitsuko         ###   ########.fr       */
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
	if (size <= 100)
		return (6);
	return (11);
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

// static int	can_swap_b(t_list *last)
// {
// 	t_list	*top;

// 	if (last == NULL || last == last->next)
// 		return (FAILURE);
// 	top = last->next;
// 	if (top->data < top->next->data)
// 		return (SUCCESS);
// 	return (FAILURE);
// }

void	move_number_to_top(t_stack *stack, int index, int stack_size)
{
	int	half_size;
	// int	can_sb;

	// can_sb = can_swap_b(stack->last_b);
	// if (index == 1)
	// {
	// 	if (can_sb == SUCCESS)
	// 		ss(stack);
	// 	else
	// 		sa(stack);
	// 	return ;
	// }
	// else if (can_sb == SUCCESS)
	// 	sb(stack);
	half_size = (stack_size / 2) + (stack_size % 2);
	if (index < half_size)
	{
		while (index != 0)
		{
			ra(stack);
			index--;
		}
		return ;
	}
	while (index != stack_size)
	{
		rra(stack);
		index++;
	}
}

void	move_number_to_top_b(t_stack *stack, int index, int stack_size)
{
	int	half_size;

	if (index == 1)
	{
		sb(stack);
		return ;
	}
	half_size = (stack_size / 2) + (stack_size % 2);
	if (index < half_size)
	{
		while (index != 0)
		{
			rb(stack);
			index--;
		}
		return ;
	}
	while (index != stack_size)
	{
		rrb(stack);
		index++;
	}
}

static void	push_small_number_pivot_to_b(t_stack *stack, int pivot)
{
	int	index;

	index = index_of_small_pivot(stack->last_a, pivot);
	while (index != -1)
	{
		if (index != 0)
			move_number_to_top(stack, index, stack->size_a);
		pb(stack);
		stack->size_b++;
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

void	sort_number_remain_a(t_stack *stack)
{
	int	size_stack;
	int	num_pushed_b;

	size_stack = 3;
	num_pushed_b = stack->size_a - size_stack;
	push_smallest_number_to_b(stack, size_stack);
	if (check_sort(stack->last_a))
		sort_three_numbers(stack);
	push_smallest_number_to_a(stack, num_pushed_b);
}

int	index_of_bigger_number(t_list *last)
{
	t_list	*temp;
	int		max;
	int		i;
	int		bigger_number_index;

	i = 0;
	bigger_number_index = i;
	temp = last->next;
	max = temp->data;
	while (temp != last)
	{
		i++;
		if (max < temp->next->data)
		{
			max = temp->next->data;
			bigger_number_index = i;
		}
		temp = temp->next;
	}
	return (bigger_number_index);
}

void	push_biggest_numbers_to_a(t_stack *stack)
{
	int		index;

	while (stack->last_b != NULL)
	{
		index = index_of_bigger_number(stack->last_b);
		if (index != 0)
			move_number_to_top_b(stack, index, stack->size_b);
		pa(stack);
		stack->size_a++;
		stack->size_b--;
	}
}

int	sort_up_to_one_hundred_numbers(t_stack *stack)
{
	// ft_putlst_fd(stack->last_a, 1);
	// ft_putstr_fd("==============================\n", 1);
	partition_a_and_push_b(stack);
	// ft_putstr_fd("==============================\n", 1);
	sort_number_remain_a(stack);
	// ft_putstr_fd("==============================\n", 1);
	push_biggest_numbers_to_a(stack);
	// ft_putstr_fd("==============================\n", 1);
	return (SUCCESS);
}
