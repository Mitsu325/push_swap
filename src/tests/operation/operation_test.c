/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:24:37 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/04/20 05:13:46 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	operation_test(void)
{
	if (swap_test())
		return (FAILURE);
	if (push_test())
		return (FAILURE);
	if (rotate_test())
		return (FAILURE);
	return (SUCCESS);
}
