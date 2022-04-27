/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:15:05 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/27 05:06:22 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	sort(t_stack *stack)
{
	if (stack->full_size == 2)
		return (sa(stack));
	if (stack->full_size == 3)
		return (sort_three_numbers(stack));
	if (stack->full_size <= 5)
		return (sort_up_to_five_numbers(stack));
	if (stack->full_size <= 10)
		return (sort_up_to_ten_numbers(stack));
	return (SUCCESS);
}
