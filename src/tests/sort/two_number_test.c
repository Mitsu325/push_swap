/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_number_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:20:33 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/26 12:21:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_sort_two_number(void)
{
	t_stack	stack;

	stack.full_size = 2;
	stack.last_a = NULL;
	ft_lstadd_back(&stack.last_a, 8);
	ft_lstadd_back(&stack.last_a, 2);
	sort(&stack);
	ft_putlst_fd(stack.last_a, 1);
	if (stack.last_a->next->data == 2 && stack.last_a->data == 8)
	{
		ft_lstclear(&stack.last_a);
		return (print_status("two_number_test.c", "test_sort_two_number",
		"OK", SUCCESS));
	}
	ft_lstclear(&stack.last_a);
	return (print_status("two_number_test.c", "test_sort_two_number",
	"Ensure sort two numbers and put operation", FAILURE));
}

int	two_number_test(void)
{
	if (test_sort_two_number())
		return (FAILURE);
	return (SUCCESS);
}
