/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:42:12 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/08 17:52:37 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: swap_ptr
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Swap pointers: ptr_a and ptr_b.
** PARAMETERS:
** #ptr_a. The integer pointer
** #ptr_b. The integer pointer
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
static void	swap_ptr(int *ptr_a, int *ptr_b)
{
	int	temp;

	temp = *ptr_a;
	*ptr_a = *ptr_b;
	*ptr_b = temp;
}

/* -------------------------------------------------------------------------- **
** FUNCTION: partition
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** The pivot is number of the highest index. It loops through the array and
** checks if the number is less than the pivot to swap the position with the
** number pointed to by pointer i. At the end, change the pivot with the highest
** number pointed by i.
** PARAMETERS:
** #num. The integer array
** #low_index. The lowest index
** #high_index. The highest index
** RETURN VALUES:
** Return the partition point.
** -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- **
** FUNCTION: quicksort
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** An array is divided into subarrays by selecting pivot element. The left and
** right subarrays are also divided using the same approach until each subarray
** contains a single element.
** PARAMETERS:
** #num. The integer array
** #low_index. The lowest index
** #high_index. The highest index
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
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
