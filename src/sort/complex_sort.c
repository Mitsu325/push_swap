/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:19:58 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/14 10:27:10 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	complex_sort(t_stack *stack)
{
	partition_a_and_push_b(stack);
	if (check_sort(stack->last_a))
		sort_up_to_five_numbers(stack);
	push_biggest_numbers_to_a(stack);
	return (SUCCESS);
}
