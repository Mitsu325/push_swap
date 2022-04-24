/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:15:05 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/24 18:43:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	sort(t_stack *stack)
{
	if (stack->size == 2)
		return (sa(stack));
	if (stack->size == 3)
		return (sort_three_numbers(stack));
	if (stack->size <= 5)
		return (sort_up_to_five_numbers(stack));
	return (SUCCESS);
}
