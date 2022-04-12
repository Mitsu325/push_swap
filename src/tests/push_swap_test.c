/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:26:14 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/12 05:38:12 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	check_list_int(void)
{
	if (check_isdigit())
		return (EXIT_FAILURE);
	if (check_is_not_digit())
		return (EXIT_FAILURE);
	if (check_isnumber())
		return (EXIT_FAILURE);
	if (check_is_not_number())
		return (EXIT_FAILURE);
	if (check_num_with_space())
		return (EXIT_FAILURE);
	if (check_not_num_with_space())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_is_int(void)
{
	if (check_is_integer())
		return (EXIT_FAILURE);
	if (check_max_integer())
		return (EXIT_FAILURE);
	if (check_min_integer())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_save(void)
{
	if (check_save_number())
		return (EXIT_FAILURE);
	if (check_save_number_with_space())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	push_swap_test(void)
{
	if (check_list_int())
		return (EXIT_FAILURE);
	if (check_is_int())
		return (EXIT_FAILURE);
	if (check_save())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
