/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_number_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:20:33 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:23 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_sort_two_number(void)
{
	t_stack	stack;

	stack.size = 2;
	stack.last = NULL;
	ft_lstadd_back(&stack.last, 8);
	ft_lstadd_back(&stack.last, 2);
	sort(&stack);
	ft_putlst_fd(stack.last, 1);
	if (stack.last->next->data == 2 && stack.last->data == 8)
	{
		ft_lstclear(&stack.last);
		return (print_status("two_number_test.c", "test_sort_two_number",
		"OK", SUCCESS));
	}
	ft_lstclear(&stack.last);
	return (print_status("two_number_test.c", "test_sort_two_number",
	"Ensure sort two numbers and put operation", FAILURE));
}

int	two_number_test(void)
{
	if (test_sort_two_number())
		return (FAILURE);
	return (SUCCESS);
}
