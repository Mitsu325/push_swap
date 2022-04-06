/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 05:26:14 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/06 08:20:48 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	push_swap_test(void)
{
	if (check_isdigit())
		return (EXIT_FAILURE);
	if (check_is_not_digit())
		return (EXIT_FAILURE);
	if (check_isnumber())
		return (EXIT_FAILURE);
	if (check_is_not_number())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
