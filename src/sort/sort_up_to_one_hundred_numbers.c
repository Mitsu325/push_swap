/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_one_hundred_numbers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 07:13:21 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/28 06:05:30 by pmitsuko         ###   ########.fr       */
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

// int	sort_up_to_one_hundred_numbers(t_stack *stack)
// {
// 	return (SUCCESS);
// }
