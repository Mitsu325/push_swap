/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a_and_push_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:30:55 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/08 17:14:05 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: get_partition
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Sets the amount of stack partitioning as per the stack size.
** PARAMETERS:
** #size. The stack size
** RETURN VALUES:
** Returns number partition.
** -------------------------------------------------------------------------- */
static int	get_partition(int size)
{
	if (size <= 100)
		return (6);
	return (11);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: save_numbers_in_array
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Save list numbers in array.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** Returns array of numbers.
** -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- **
** FUNCTION: get_pivot
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Get the pivot number. Uses the array of sorted numbers and looks for the
** index which is multiplying the stack size with the factor and dividing by the
** partitioning amount.
** PARAMETERS:
** #sorted_number. The integer array of sorted
** #size. The stack size
** #factor. The multiplication factor
** #divisor. The divider
** RETURN VALUES:
** Returns the pivot number.
** -------------------------------------------------------------------------- */
static int	get_pivot(int *sorted_number, int size, int factor, int divisor)
{
	int	pivot;

	pivot = sorted_number[((size * factor) / divisor)];
	return (pivot);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: partition_a_and_push_b
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Partition the stack a to determinate the pivot and push numbers less than the
** pivot to stack b.
** PARAMETERS:
** #stack. The t_stack struct
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
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