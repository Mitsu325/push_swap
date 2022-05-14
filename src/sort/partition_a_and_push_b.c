/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a_and_push_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:30:55 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 19:52:11 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_partition(int size)
{
	if (size <= 50)
		return (2);
	if (size <= 150)
		return (4);
	if (size <= 250)
		return (6);
	if (size <= 350)
		return (8);
	return (10);
}

static int	*save_numbers_in_array(t_stack *stack)
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

static int	get_pivot(int *sorted_number, int size, int divisor)
{
	int	pivot;

	pivot = sorted_number[(size / divisor)];
	return (pivot);
}

void	partition_a_and_push_b(t_stack *stack)
{
	int		*sorted_num;
	t_pivot	pvt;
	int	i;

	sorted_num = save_numbers_in_array(stack);
	quicksort(sorted_num, 0, stack->full_size - 1);
	i = 0;
	while (stack->size_a > 5)
	{
		pvt.partition = get_partition(stack->size_a);
		pvt.num = get_pivot(sorted_num + i, stack->size_a, pvt.partition);
		pvt.half = get_pivot(sorted_num + i, stack->size_a, pvt.partition * 2);
		push_small_number_pivot_to_b(stack, pvt);
		i += (stack->size_a / pvt.partition);
	}
	free(sorted_num);
}
